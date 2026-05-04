

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


struct SinhVien {
    int    maso;
    char   hoten[50];
    int    tuoi;
    char   diachi[100];
};


struct Node {
    SinhVien data;
    Node* next;   

   
    Node(SinhVien sv) {
        data = sv;
        next = NULL;
    }
};


struct DanhSach {
    Node* head;   
    DanhSach() {
        head = NULL;
    }

    
    void xemDanhSach() {
        if (head == NULL) {
            cout << "  [Danh sach trong!]\n";
            return;
        }

        Node* temp = head;
        int   stt = 1;
        cout << "  STT | Ma so | Ho va ten                  | Tuoi | Dia chi\n";
        cout << "  ----|-------|----------------------------|------|------------------\n";
        while (temp != NULL) {
            cout << "  " << stt++ << "   | "
                << temp->data.maso << "     | "
                << temp->data.hoten << "    | "
                << temp->data.tuoi << "   | "
                << temp->data.diachi << "\n";
            temp = temp->next;
        }
    }

   
    void themSinhVien(SinhVien sv) {
        Node* newNode = new Node(sv);   
        if (head == NULL) {
            head = newNode;
            return;
        }

       
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

   
    void xoaSinhVien(int maso) {
        if (head == NULL) {
            cout << "  Danh sach trong, khong co gi de xoa!\n";
            return;
        }

        
        if (head->data.maso == maso) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "  Da xoa sinh vien co ma so " << maso << ".\n";
            return;
        }

        
        Node* current = head;
        while (current->next != NULL && current->next->data.maso != maso) {
            current = current->next;
        }

        if (current->next == NULL) {
            cout << "  Khong tim thay sinh vien co ma so " << maso << "!\n";
            return;
        }

        
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << "  Da xoa sinh vien co ma so " << maso << ".\n";
    }

    
    void timSinhVien(int maso) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data.maso == maso) {
                cout << "  === Tim thay ===\n";
                cout << "  Ma so  : " << temp->data.maso << "\n";
                cout << "  Ho ten : " << temp->data.hoten << "\n";
                cout << "  Tuoi   : " << temp->data.tuoi << "\n";
                cout << "  Dia chi: " << temp->data.diachi << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "  Khong tim thay sinh vien co ma so " << maso << "!\n";
    }

    
    void ghiFile(const char* tenFile) {
        ofstream outFile(tenFile, ios::binary);
        if (!outFile) {
            cout << "  Loi: Khong the mo file de ghi!\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            
            outFile.write((char*)&temp->data, sizeof(SinhVien));
            temp = temp->next;
        }
        outFile.close();
        cout << "  Da ghi du lieu vao file \"" << tenFile << "\".\n";
    }

    
    void docFile(const char* tenFile) {
        ifstream inFile(tenFile, ios::binary);
        if (!inFile) {
            cout << "  Loi: Khong the mo file de doc (co the chua co file)!\n";
            return;
        }

       
        xoaHet();

        SinhVien sv;
        int      soLuong = 0;
        while (inFile.read((char*)&sv, sizeof(SinhVien))) {
            themSinhVien(sv);
            soLuong++;
        }
        inFile.close();
        cout << "  Da doc " << soLuong << " sinh vien tu file \"" << tenFile << "\".\n";
    }
   
    void xoaHet() {
        Node* current = head;
        while (current != NULL) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = NULL;
    }
};


SinhVien nhapSinhVien() {
    SinhVien sv;
    cout << "  + Ma so  : ";  cin >> sv.maso;
    cin.ignore();   
    cout << "  + Ho ten : ";  cin.getline(sv.hoten, 50);
    cout << "  + Tuoi   : ";  cin >> sv.tuoi;
    cin.ignore();
    cout << "  + Dia chi: ";  cin.getline(sv.diachi, 100);
    return sv;
}

int main() {
    DanhSach ds;
    const char* TEN_FILE = "sinhvien.dla.edu.vn";
    int chon;

    do {
        system("cls");   
        cout << "============================================\n";
        cout << "    PHAN MEM QUAN LY SINH VIEN\n";
        cout << "============================================\n";
        cout << "  1. Xem danh sach sinh vien\n";
        cout << "  2. Them 1 sinh vien\n";
        cout << "  3. Xoa 1 sinh vien (theo ma so)\n";
        cout << "  4. Tim sinh vien theo ma so\n";
        cout << "  5. Ghi du lieu ra tap tin nhi phan\n";
        cout << "  6. Doc du lieu tu tap tin nhi phan\n";
        cout << "  0. Thoat\n";
        cout << "============================================\n";
        cout << "  Chon: ";
        cin >> chon;

        cout << "\n";

        switch (chon) {
        case 1:
            cout << "--- DANH SACH SINH VIEN ---\n";
            ds.xemDanhSach();
            break;

        case 2: {
            cout << "--- THEM SINH VIEN MOI ---\n";
            SinhVien sv = nhapSinhVien();
            ds.themSinhVien(sv);
            cout << "  Da them thanh cong!\n";
            break;
        }

        case 3: {
            cout << "--- XOA SINH VIEN ---\n";
            int maso;
            cout << "  Nhap ma so can xoa: ";
            cin >> maso;
            ds.xoaSinhVien(maso);
            break;
        }

        case 4: {
            cout << "--- TIM SINH VIEN ---\n";
            int maso;
            cout << "  Nhap ma so can tim: ";
            cin >> maso;
            ds.timSinhVien(maso);
            break;
        }

        case 5:
            cout << "--- GHI FILE ---\n";
            ds.ghiFile(TEN_FILE);
            break;
        case 6:
            cout << "--- DOC FILE ---\n";
            ds.docFile(TEN_FILE);
            break;

        case 0:
            cout << "  Tam biet!\n";
            break;

        default:
            cout << "  Lua chon khong hop le! Vui long chon lai.\n";
        }

        if (chon != 0) {
            cout << "\n  Nhan Enter de tiep tuc...";
            cin.ignore();
            cin.get();
        }

    } while (chon != 0);

   
    ds.xoaHet();
    return 0;
}