#include <iostream>
#include <string>
using namespace std;

void bai1_tachHoTen() {
    cout << "\n========== BAI 1: TACH HO LOT VA TEN ==========" << endl;

    string hoTen;
    cout << "Nhap ho va ten: ";
    getline(cin, hoTen); 
    int viTriCuoi = hoTen.rfind(' ');

    if (viTriCuoi == string::npos) {
        
        cout << "Ho lot: (khong co)" << endl;
        cout << "Ten   : " << hoTen << endl;
    }
    else {
        string hoLot = hoTen.substr(0, viTriCuoi); 
        string ten = hoTen.substr(viTriCuoi + 1);  

        cout << "Ho lot: " << hoLot << endl;
        cout << "Ten   : " << ten << endl;
    }
}


void bai2_xoaKyTu() {
    cout << "\n========== BAI 2: XOA KY TU TRONG CHUOI ==========" << endl;

    string chuoi;
    char kyTuXoa;

    cout << "Nhap mot chuoi bat ky: ";
    getline(cin, chuoi);

    cout << "Nhap ky tu muon xoa: ";
    cin >> kyTuXoa;
    cin.ignore(); 
    string ketQua = "";
    for (char c : chuoi) {
        if (c != kyTuXoa) {
            ketQua += c; 
        }
    }

    cout << "Chuoi sau khi xoa '" << kyTuXoa << "': " << ketQua << endl;
}


void bai3_kiemTraDoiXung() {
    cout << "\n========== BAI 3: KIEM TRA CHUOI DOI XUNG ==========" << endl;

    string chuoi;
    cout << "Nhap mot chuoi: ";
    getline(cin, chuoi);

    int n = chuoi.length();
    bool doiXung = true;

   
    for (int i = 0; i < n / 2; i++) {
        if (chuoi[i] != chuoi[n - 1 - i]) {
            doiXung = false;
            break;
        }
    }

    if (doiXung) {
        cout << "\"" << chuoi << "\" LA chuoi doi xung!" << endl;
    }
    else {
        cout << "\"" << chuoi << "\" KHONG phai chuoi doi xung!" << endl;
    }
}

void bai4_timViTriCuoiCung() {
    cout << "\n========== BAI 4: TIM VI TRI CUOI CUNG CUA KY TU ==========" << endl;

    string chuoi;
    char kyTuTim;

    cout << "Nhap chuoi X: ";
    getline(cin, chuoi);

    cout << "Nhap ky tu Y can tim: ";
    cin >> kyTuTim;
    cin.ignore();

    
    size_t viTri = chuoi.rfind(kyTuTim);

    if (viTri == string::npos) {
        cout << "Ky tu '" << kyTuTim << "' KHONG xuat hien trong chuoi." << endl;
    }
    else {
        cout << "Ky tu '" << kyTuTim << "' xuat hien cuoi cung tai vi tri: " << viTri << endl;
        
        cout << "(Vi tri thu " << viTri + 1 << " neu tinh tu 1)" << endl;
    }
}

int main() {
    int luaChon;

    cout << "====================================" << endl;
    cout << "  CHUONG TRINH BAI TAP CHUOI KY TU" << endl;
    cout << "====================================" << endl;
    cout << "1. Tach ho lot va ten" << endl;
    cout << "2. Xoa ky tu trong chuoi" << endl;
    cout << "3. Kiem tra chuoi doi xung" << endl;
    cout << "4. Tim vi tri cuoi cung cua ky tu" << endl;
    cout << "0. Chay tat ca bai tap" << endl;
    cout << "Chon: ";
    cin >> luaChon;
    cin.ignore(); 

    switch (luaChon) {
    case 1: bai1_tachHoTen();      break;
    case 2: bai2_xoaKyTu();        break;
    case 3: bai3_kiemTraDoiXung(); break;
    case 4: bai4_timViTriCuoiCung(); break;
    case 0:
        bai1_tachHoTen();
        bai2_xoaKyTu();
        bai3_kiemTraDoiXung();
        bai4_timViTriCuoiCung();
        break;
    default:
        cout << "Lua chon khong hop le!" << endl;
    }

    cout << "\n==== KET THUC CHUONG TRINH ====" << endl;
    return 0;
}