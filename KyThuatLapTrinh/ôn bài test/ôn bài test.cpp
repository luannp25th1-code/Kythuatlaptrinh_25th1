#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <cstdlib> // ?? dùng system("cls")
using namespace std;

struct Vehicle {
	int id;
	char type[30]; // ví d?: Sirus, Wave 50
	string branch; // ví d?: Toyota, Yamaha
	double price;

	friend istream& operator>>(istream& in, Vehicle& v) {
		cout << "Enter vehicle information:" << endl;
		cout << "\t+ Id: ";
		in >> v.id;
		cout << "\t+ Type (Sirus/Wave50/...): ";
		in >> v.type;
		cout << "\t+ Branch (Toyota/Yamaha/...): ";
		in.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(in, v.branch);
		cout << "\t+ Price: ";
		in >> v.price;
		return in;
	}

	friend ostream& operator<<(ostream& out, Vehicle v) {

		out << "Vehicle information:" << endl;
		out << "\t+ Id : " << v.id << endl;
		out << "\t+ Type : " << v.type << endl;
		out << "\t+ Branch : " << v.branch << endl;
		out << "\t+ Price : " << v.price << endl;
		return out;
	}
};

void Show(vector<Vehicle> v) {
	if (v.empty()) {
		cout << "No vehicle in list!" << endl;
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
}

void Find(vector<Vehicle> v, string branch) {
	bool found = false;
	for (int i = v.size() - 1; i >= 0; i--) {
		if (v[i].branch == branch) {
			found = true;
			cout << v[i];
		}
	}
	if (!found)
		cout << "No vehicle found with branch: " << branch << endl;

}

bool Remove(vector<Vehicle>& v, int id) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].id == id) {
			v.erase(v.begin() + i);
			return true;
		}
	}
	return false;
}

void Export(vector<Vehicle> v, string filename) {
	ofstream out(filename, ios::binary);
	if (!out.is_open()) {
		cout << "Can't open file: " << filename << endl;
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		out.write(reinterpret_cast<const char*>(&v[i].id), sizeof(v[i].id));
		out.write(v[i].type, sizeof(v[i].type));

		size_t branchLength = v[i].branch.size();
		out.write(reinterpret_cast<const char*>(&branchLength), sizeof(branchLength));
		out.write(v[i].branch.c_str(), branchLength);

		out.write(reinterpret_cast<const char*>(&v[i].price), sizeof(v[i].price));
	}
	out.close();

	cout << "Export successfully to file: " << filename << endl;
}

void Import(vector<Vehicle>& v, string filename) {
	ifstream in(filename, ios::binary);
	if (!in.is_open()) {
		cout << "Can't open file: " << filename << endl;
		return;
	}
	v.clear();
	Vehicle a;
	while (in.peek() != EOF) {
		in.read(reinterpret_cast<char*>(&a.id), sizeof(a.id));
		in.read(a.type, sizeof(a.type));

		size_t branchLength;
		in.read(reinterpret_cast<char*>(&branchLength), sizeof(branchLength));
		a.branch.resize(branchLength);
		in.read(&a.branch[0], branchLength);

		in.read(reinterpret_cast<char*>(&a.price), sizeof(a.price));

		v.push_back(a);
	}
	in.close();
	cout << "Import successfully from file: " << filename << endl;
}

bool Update(vector<Vehicle>& v, int id) {

	for (int i = 0; i < v.size(); i++) {
		if (v[i].id == id) {
			cout << "Enter new information for vehicle id " << id << ":" << endl;
			cin >> v[i];
			return true;
		}
	}
	return false;
}

void Statistics(vector<Vehicle> v) {
	int toyota = 0, yamaha = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].branch == "Toyota") toyota++;
		else if (v[i].branch == "Yamaha") yamaha++;
	}
	cout << "Statistics by branch:" << endl;
	cout << "\t+ Toyota : " << toyota << endl;
	cout << "\t+ Yamaha : " << yamaha << endl;
}

int main() {
	vector<Vehicle> list;
	int choice;

	do {
		system("cls"); // xoá màn hình tr??c khi in menu

		cout << "\n===== VEHICLE MANAGEMENT =====" << endl;

		cout << "1. Xem danh sach" << endl;
		cout << "2. Them 1 chiec xe" << endl;
		cout << "3. Tim kiem xe" << endl;
		cout << "4. Xoa 1 chiec xe" << endl;
		cout << "5. Luu tap tin" << endl;
		cout << "6. Doc tap tin" << endl;
		cout << "7. Cap nhat thong tin xe" << endl;
		cout << "8. Thong ke xe theo nhan hieu" << endl;
		cout << "0. Thoat" << endl;
		cout << "Your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: Show(list); break;
		case 2: { Vehicle a; cin >> a; list.push_back(a); break; }
		case 3: {
			string branch;
			cout << "Enter branch to find: ";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			getline(cin, branch);
			Find(list, branch);
			break;
		}
		case 4: {
			int removeId;
			cout << "Enter id to remove: ";
			cin >> removeId;
			if (Remove(list, removeId))
				cout << "Remove successfully!" << endl;

			else
				cout << "Id not found. Try again!" << endl;
			break;
		}
		case 5: Export(list, "NPCL"); break;
		case 6: Import(list, "NPCL"); break;
		case 7: {
			int updateId;
			cout << "Enter id to update: ";
			cin >> updateId;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (Update(list, updateId))
				cout << "Update successfully!" << endl;
			else
				cout << "Id not found. Try again!" << endl;
			break;
		}
		case 8: Statistics(list); break;
		case 0: return 0;
		default: cout << "Your command isn't found. Try again!" << endl;
		}

		cout << "\n"; // xu?ng dòng cho ??p
		system("pause"); // d?ng l?i ch? phím b?t k?, sau ?ó s? xoá màn hình ? vòng

	} while (true);

	return 0;

}