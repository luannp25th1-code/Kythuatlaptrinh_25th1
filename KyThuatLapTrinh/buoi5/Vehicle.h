#pragma once
#include "Vehicle.h"
#include <string>
using namespace std;

struct Node {
	Vehicle data;
	Node* next;
	Node(Vehicle v) : data(v), next(nullptr) {}
};

class SingleLinkedList {
private:
	Node* head;

	// Tim node theo ID
	Node* findById(int id) {
		Node* cur = head;
		while (cur) {
			if (cur->data.id == id) return cur;
			cur = cur->next;
		}
		return nullptr;

	}

public:
	SingleLinkedList() : head(nullptr) {}

	~SingleLinkedList() {
		Node* cur = head;
		while (cur) { Node* tmp = cur; cur = cur->next; delete tmp; }
	}

	// 1. Xem danh sach
	void Show();

	// 2. Them xe vao cuoi
	void AddTail(Vehicle v);

	// 3. Tim kiem theo loai xe hoac nhan hieu
	void Search(string term);

	// 4. Xoa xe theo ID
	void Delete(int id);

	// 5. Luu file
	void Export(const char* filename);

	// 6. Doc file
	void Import(const char* filename);

	// 7. Cap nhat thong tin xe

	void Update(int id);

	// 8. Thong ke theo nhan hieu
	void ThongKe();
};
==> Header(Singlelinkedlist.h)
#pragma once
#include <iostream>
#include <cstdio>
#include <cstring>
#include <fstream>
using namespace std;

struct Vehicle {
	int id;
	char type[30];
	char branch[30];
	double price;

	Vehicle() {
		id = 0;
		memset(type, 0, sizeof(type));
		memset(branch, 0, sizeof(branch));
		price = 0;
	}

	friend istream& operator>>(istream& is, Vehicle& v) {
		cout << " Nhap ID xe : "; is >> v.id;
		is.ignore();

		cout << " Nhap loai xe : "; is.getline(v.type, 30);
		cout << " Nhap nhan hieu : "; is.getline(v.branch, 30);
		cout << " Nhap gia (VND) : ";
		while (!(is >> v.price) || v.price < 0) {
			is.clear(); is.ignore(1000, '\n');
			cout << " [!] Gia khong hop le. Nhap lai: ";
		}
		return is;
	}

	friend ostream& operator<<(ostream& os, const Vehicle& v) {
		char buf[64];
		snprintf(buf, sizeof(buf), "%.0f", v.price);
		os << " ID: " << v.id
			<< " | Loai xe: " << v.type
			<< " | Nhan hieu: " << v.branch
			<< " | Gia: " << buf << " VND";
		return os;
	}

	void writeToFile(FILE* f) const {
		fwrite(this, sizeof(Vehicle), 1, f);
	}

	void readFromFile(FILE* f) {
		fread(this, sizeof(Vehicle), 1, f);
	}
};
