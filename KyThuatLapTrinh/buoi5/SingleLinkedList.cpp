#define _CRT_SECURE_NO_WARNINGS // Tat canh bao fopen/strncpy khong an
#include "SingleLinkedList.h"
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <cstdio>
#include <cstring>
using namespace std;

static string toLower(string s) {
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}

// ==================== 1. SHOW ====================
void SingleLinkedList::Show() {
	if (!head) {
		cout << "\n [!] Danh sach xe trong!\n";
		return;
	}
	cout << "\n " << string(70, '-') << "\n";
	cout << " " << left
		<< setw(6) << "ID"
		<< setw(20) << "Loai xe"

		<< setw(18) << "Nhan hieu"
		<< setw(15) << "Gia (VND)" << "\n";
	cout << " " << string(70, '-') << "\n";
	Node* cur = head;
	while (cur) {
		char buf[64];
		snprintf(buf, sizeof(buf), "%.0f", cur->data.price);
		cout << " "
			<< setw(6) << cur->data.id
			<< setw(20) << cur->data.type
			<< setw(18) << cur->data.branch
			<< setw(15) << buf << "\n";
		cur = cur->next;
	}
	cout << " " << string(70, '-') << "\n";
}

// ==================== 2. ADD TAIL ====================
void SingleLinkedList::AddTail(Vehicle v) {
	if (findById(v.id)) {
		cout << " [!] ID " << v.id << " da ton tai! Vui long chon ID khac.\n";
		return;
	}
	Node* newNode = new Node(v);
	if (!head) {
		head = newNode;
	}
	else {
		Node* cur = head;

		while (cur->next) cur = cur->next;
		cur->next = newNode;
	}
	cout << " [OK] Da them xe thanh cong!\n";
}

// ==================== 3. SEARCH ====================
void SingleLinkedList::Search(string term) {
	string kw = toLower(term);
	bool found = false;
	cout << "\n " << string(70, '-') << "\n";
	cout << " " << left
		<< setw(6) << "ID"
		<< setw(20) << "Loai xe"
		<< setw(18) << "Nhan hieu"
		<< setw(15) << "Gia (VND)" << "\n";
	cout << " " << string(70, '-') << "\n";
	Node* cur = head;
	while (cur) {
		string loai = toLower(string(cur->data.type));
		string nhan = toLower(string(cur->data.branch));
		if (loai.find(kw) != string::npos || nhan.find(kw) != string::npos) {
			char buf[64];
			snprintf(buf, sizeof(buf), "%.0f", cur->data.price);
			cout << " "
				<< setw(6) << cur->data.id
				<< setw(20) << cur->data.type
				<< setw(18) << cur->data.branch
				<< setw(15) << buf << "\n";

			found = true;
		}
		cur = cur->next;
	}
	if (!found)
		cout << " [!] Khong tim thay xe voi tu khoa \"" << term << "\"\n";
	cout << " " << string(70, '-') << "\n";
}

// ==================== 4. DELETE ====================
void SingleLinkedList::Delete(int id) {
	if (!head) {
		cout << " [!] Danh sach trong!\n";
		return;
	}

	// Truong hop xoa node dau
	if (head->data.id == id) {
		cout << " Xe can xoa: " << head->data << "\n";
		char confirm;
		cout << " Xac nhan xoa? (y/n): ";
		cin >> confirm;
		if (confirm == 'y' || confirm == 'Y') {
			Node* tmp = head;
			head = head->next;
			delete tmp;
			cout << " [OK] Da xoa xe thanh cong!\n";
		}
		else {

			cout << " [!] Da huy thao tac xoa.\n";
		}
		return;
	}

	// Tim node truoc node can xoa
	Node* prev = head;
	while (prev->next && prev->next->data.id != id)
		prev = prev->next;

	if (!prev->next) {
		cout << " [!] Khong tim thay xe co ID = " << id << "\n";
		return;
	}

	Node* target = prev->next;
	cout << " Xe can xoa: " << target->data << "\n";
	char confirm;
	cout << " Xac nhan xoa? (y/n): ";
	cin >> confirm;
	if (confirm == 'y' || confirm == 'Y') {
		prev->next = target->next;
		delete target;
		cout << " [OK] Da xoa xe thanh cong!\n";
	}
	else {
		cout << " [!] Da huy thao tac xoa.\n";
	}
}

// ==================== 5. EXPORT ====================
void SingleLinkedList::Export(const char* filename) {
	FILE* f = fopen(filename, "wb");
	if (!f) {
		cout << " [!] Khong the mo file de ghi!\n";
		return;
	}
	int count = 0;
	Node* cur = head;
	while (cur) { count++; cur = cur->next; }

	fwrite(&count, sizeof(int), 1, f);
	cur = head;
	while (cur) {
		cur->data.writeToFile(f);
		cur = cur->next;
	}
	fclose(f);
	cout << " [OK] Da luu " << count << " xe vao file \"" << filename << "\"\n";
}

// ==================== 6. IMPORT ====================
void SingleLinkedList::Import(const char* filename) {
	FILE* f = fopen(filename, "rb");
	if (!f) {
		cout << " [!] Khong tim thay file \"" << filename << "\"\n";
		return;
	}

	// Xoa danh sach hien tai
	Node* cur = head;
	while (cur) { Node* tmp = cur; cur = cur->next; delete tmp; }
	head = nullptr;

	int count = 0;
	fread(&count, sizeof(int), 1, f);
	for (int i = 0; i < count; i++) {
		Vehicle v;
		v.readFromFile(f);
		Node* newNode = new Node(v);
		if (!head) {
			head = newNode;
		}
		else {
			Node* tail = head;
			while (tail->next) tail = tail->next;
			tail->next = newNode;
		}
	}
	fclose(f);
	cout << " [OK] Da doc " << count << " xe tu file \"" << filename << "\"\n";
}

// ==================== 7. UPDATE ====================
void SingleLinkedList::Update(int id) {
	Node* node = findById(id);
	if (!node) {

		cout << " [!] Khong tim thay xe co ID = " << id << "\n";
		return;
	}

	cout << " Thong tin hien tai:\n";
	cout << " Loai xe : " << node->data.type << "\n";
	cout << " Nhan hieu: " << node->data.branch << "\n";
	char buf[64];
	snprintf(buf, sizeof(buf), "%.0f", node->data.price);
	cout << " Gia : " << buf << " VND\n";

	cout << "\n Nhap thong tin moi (Enter de giu nguyen):\n";
	cin.ignore();

	char newType[30];
	cout << " Loai xe moi : ";
	cin.getline(newType, 30);
	if (strlen(newType) > 0)
		strncpy(node->data.type, newType, 29);

	char newBranch[30];
	cout << " Nhan hieu moi: ";
	cin.getline(newBranch, 30);
	if (strlen(newBranch) > 0)
		strncpy(node->data.branch, newBranch, 29);

	cout << " Gia moi (0 de giu nguyen): ";
	double newPrice;
	cin >> newPrice;

	if (newPrice > 0)
		node->data.price = newPrice;

	cin.ignore(); // xoa '\n' con lai trong buffer
	cout << " [OK] Da cap nhat thong tin xe!\n";
}

// ==================== 8. THONG KE ====================
void SingleLinkedList::ThongKe() {
	if (!head) {
		cout << "\n [!] Danh sach xe trong!\n";
		return;
	}

	map<string, int> counter;
	Node* cur = head;
	while (cur) {
		counter[string(cur->data.branch)]++;
		cur = cur->next;
	}

	cout << "\n --- THONG KE XE THEO NHAN HIEU ---\n";
	cout << " " << string(35, '-') << "\n";
	cout << " " << left << setw(20) << "Nhan hieu" << setw(10) << "So luong" << "\n";
	cout << " " << string(35, '-') << "\n";
	for (const auto& kv : counter)
		cout << " " << setw(20) << kv.first << setw(10) << kv.second << "\n";
	cout << " " << string(35, '-') << "\n";

	int total = 0;
	cur = head;
	while (cur) { total++; cur = cur->next; }
	cout << " Tong so xe: " << total << "\n";
}