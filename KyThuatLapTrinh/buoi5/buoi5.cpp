#include <iostream>
#include <string>
#include "Vehicle.h"
#include "SingleLinkedList.h"
using namespace std;

int main()
{
	SingleLinkedList danhSach;
	do {
		// system("cls"); // Windows only - bo comment khi chay tren Windows
		cout << "\n------QUAN LY PHUONG TIEN XE------" << endl;
		cout << "1. Xem danh sach" << endl;
		cout << "2. Them 1 chiec xe" << endl;
		cout << "3. Tim kiem xe" << endl;
		cout << "4. Xoa 1 chiec xe" << endl;
		cout << "5. Luu tap tin" << endl;
		cout << "6. Doc tap tin" << endl;
		cout << "7. Cap nhat thong tin xe" << endl;
		cout << "8. Thong ke xe theo nhan hieu" << endl;
		cout << "0. Thoat" << endl;
		cout << "----------------------------------" << endl;
		cout << "Chon chuc nang: ";
		int choice;
		cin >> choice;

		switch (choice) {
		case 1: {
			cout << "1. XEM DANH SACH" << endl;

			danhSach.Show();
			break;
		}
		case 2: {
			cout << "2. THEM 1 CHIEC XE" << endl;
			Vehicle v;
			cin >> v;
			danhSach.AddTail(v);
			break;
		}
		case 3: {
			cout << "3. TIM KIEM XE" << endl;
			string searchTerm;
			cin.ignore();
			cout << " Nhap loai xe hoac nhan hieu: ";
			getline(cin, searchTerm);
			danhSach.Search(searchTerm);
			break;
		}
		case 4: {
			cout << "4. XOA 1 CHIEC XE" << endl;
			cout << " Nhap ID xe can xoa: ";
			int id;
			cin >> id;
			danhSach.Delete(id);
			break;
		}
		case 5: {
			cout << "5. LUU TAP TIN" << endl;

			danhSach.Export("vehicles.dat");
			break;
		}
		case 6: {
			cout << "6. DOC TAP TIN" << endl;
			danhSach.Import("vehicles.dat");
			break;
		}
		case 7: {
			cout << "7. CAP NHAT THONG TIN XE" << endl;
			cout << " Nhap ID xe can cap nhat: ";
			int id;
			cin >> id;
			danhSach.Update(id);
			break;
		}
		case 8: {
			cout << "8. THONG KE XE THEO NHAN HIEU" << endl;
			danhSach.ThongKe();
			break;
		}
		case 0: {
			cout << "Tam biet!" << endl;
			return 0;
		}
		default: {
			cout << " [!] Lua chon khong hop le. Vui long chon lai." << endl;
			break;
		}

		}
		system("pause"); // Windows only
		cout << "\nNhan Enter de tiep tuc..." << endl;
	} while (true);
}