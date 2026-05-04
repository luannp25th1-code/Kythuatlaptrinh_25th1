#include <iostream>
#include <vector>
using namespace std;


void YeuCau1() {
    cout << "=== YEU CAU 1: Duyet mang bang con tro ===" << endl;

    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]); 
    int* p = arr; 
    cout << "In bang *(p + i):" << endl;
    for (int i = 0; i < n; i++) {
        cout << *(p + i) << " ";
    }
    cout << endl;

    cout << "In bang p[i]:" << endl;
    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}


void YeuCau2() {
    cout << "\n=== YEU CAU 2: Lam viec voi vector int ===" << endl;

    vector<int> v;

   
    int n;
    cout << "Nhap so luong phan tu n: ";
    cin >> n;

    cout << "Nhap " << n << " phan tu:" << endl;
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Phan tu [" << i << "]: ";
        cin >> x;
        v.push_back(x); 
    }

   
    cout << "\nVector hien tai: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

   
    int them;
    cout << "\nNhap phan tu muon them vao cuoi: ";
    cin >> them;
    v.push_back(them);

    cout << "Vector sau khi them: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    
    cout << "\nXoa phan tu cuoi..." << endl;
    v.pop_back();

    cout << "Vector sau khi xoa phan tu cuoi: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main() {
    YeuCau1();
    YeuCau2();

    return 0;
}