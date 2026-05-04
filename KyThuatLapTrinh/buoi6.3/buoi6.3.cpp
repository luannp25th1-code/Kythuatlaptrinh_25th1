#include <iostream>
#include <string>
using namespace std;

int demSoTu(const string& chuoi) {
    int soTu = 0;
    bool dangTrongTu = false; 
    for (int i = 0; i < chuoi.length(); i++) {
        if (chuoi[i] != ' ') {
            
            if (!dangTrongTu) {
                soTu++;             
                dangTrongTu = true;
            }
        }
        else {
           
            dangTrongTu = false;
        }
    }

    return soTu;
}

void bai1_demSoTu() {
    cout << "\n========== BAI 1: DEM SO TU TRONG CHUOI ==========" << endl;

    string chuoi;
    cout << "Nhap mot chuoi bat ky: ";
    getline(cin, chuoi);

    int soTu = demSoTu(chuoi);
    cout << "So tu trong chuoi: " << soTu << " tu" << endl;
}


string vietHoaDauTu(const string& chuoi) {
    string ketQua = chuoi;  
    bool dauTu = true;      

    for (int i = 0; i < ketQua.length(); i++) {
        if (ketQua[i] == ' ') {
          
            dauTu = true;
        }
        else {
            if (dauTu && ketQua[i] >= 'a' && ketQua[i] <= 'z') {
               
                ketQua[i] = ketQua[i] - 32;
            }
            dauTu = false; 
        }
    }

    return ketQua;
}

void bai2_vietHoaDauTu() {
    cout << "\n========== BAI 2: VIET HOA CHU CAI DAU MOI TU ==========" << endl;

    string chuoi;
    cout << "Nhap mot chuoi bat ky: ";
    getline(cin, chuoi);

    string ketQua = vietHoaDauTu(chuoi);
    cout << "Chuoi goc  : " << chuoi << endl;
    cout << "Chuoi moi  : " << ketQua << endl;
}


int main() {
    int luaChon;

    cout << "====================================" << endl;
    cout << "   QUESTION 12 - BAI TAP CHUOI      " << endl;
    cout << "====================================" << endl;
    cout << "1. Dem so tu trong chuoi" << endl;
    cout << "2. Viet hoa chu cai dau moi tu" << endl;
    cout << "0. Chay ca hai bai" << endl;
    cout << "Chon: ";
    cin >> luaChon;
    cin.ignore(); 

    switch (luaChon) {
    case 1: bai1_demSoTu();      break;
    case 2: bai2_vietHoaDauTu(); break;
    case 0:
        bai1_demSoTu();
        bai2_vietHoaDauTu();
        break;
    default:
        cout << "Lua chon khong hop le!" << endl;
    }

    cout << "\n==== KET THUC CHUONG TRINH ====" << endl;
    return 0;
}