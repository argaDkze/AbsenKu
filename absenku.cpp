#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 500;
string nama[MAX];
char statusArr[MAX];
int n = 0;

// Deklarasi fungsi
void tampilkanMenu();
void inputData();
void bacaFile();
void urutkanNama();
void tampilkanAbsen();
void rekapKehadiran();
int cariNama(const string &key);
void ubahStatus();



void ubahStatus() {
    bacaFile();
    if (n == 0) {
        cout << "Data absensi kosong.\n";
        return;
    }
    string key;
    cout << "Masukkan nama yang ingin diubah: ";
    cin.ignore(); // pastikan buffer bersih sebelum getline
    getline(cin, key);

    int idx = cariNama(key);
    if (idx == -1) {
        cout << "Nama tidak ditemukan.\n";
        return;
    }

    cout << "Status saat ini: " << statusArr[idx] << "\n";
    char baru;
    cout << "Masukkan status baru (H/T): ";
    cin >> baru;
    cin.ignore();
    if (baru == 'h') baru = 'H';
    if (baru == 't') baru = 'T';
    if (baru != 'H' && baru != 'T') {
        cout << "Input status tidak valid. Perubahan dibatalkan.\n";
        return;
    }

    statusArr[idx] = baru;

    // tulis ulang file (overwrite)
    ofstream file("absensi.txt", ios::trunc);
    if (!file) {
        cout << "Gagal membuka file untuk menulis.\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        file << nama[i] << "|" << statusArr[i] << "\n";
    }
    file.close();
    cout << "Status berhasil diperbarui dan file disimpan.\n";
}
