#include <iostream>
using namespace std;

void tampilMenu() {
    for (int i = 0; i < 50; i++) {
        cout << "=";
        if (i == 24) {
            cout << " Absensi Harian ";
            continue;
        }
    }
    cout << endl;
    cout << "1. Input Data" << endl;
    cout << "2. Baca File" << endl;
    cout << "3. Cari Nama" << endl;
    cout << "4. Rekap Absensi" << endl;
    cout << "5. Ubah Status" << endl;
    cout << "6. Keluar" << endl;
    cout << "Masukkan pilihan kamu: ";
}

int main() {
    int pilihan;
    bool jalan = true;
    do {
        tampilMenu();
        cin >> pilihan;
    if (pilihan == 1) {
        inputData();
    } else if (pilihan == 2) {
        tampilBacaFile();
    } else if (pilihan == 3) {
        menuCariNama();
    } else if (pilihan == 4) {
        rekapKehadiran();
    } else if (pilihan == 5) {
        ubahStatus();
    } else if (pilihan == 6) {
        jalan = false;
    }
    } while (jalan);
    return 0;
}