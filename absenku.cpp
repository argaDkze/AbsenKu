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

void tampilkanMenu() {
    cout << "\n===== MENU ABSENSI =====\n";
    cout << "1. Input Data Absen\n";
    cout << "2. Tampilkan Absen (A-Z)\n";
    cout << "3. Cari Nama\n";
    cout << "4. Rekap Kehadiran\n";
    cout << "5. Ubah Status\n";
    cout << "6. Keluar\n";
    cout << "========================\n";
}

void bacaFile() {
    ifstream file("absensi.txt");
    n = 0;
    if (!file) {
        return;
    }
    string line;
    while (getline(file, line)) {
        int pos = line.find('|');
        if (pos != string::npos) {
            nama[n] = line.substr(0, pos);
            string right = line.substr(pos + 1);
            char st = 'T';
            for (size_t k = 0; k < right.size(); k++) {
                if (right[k] != ' ' && right[k] != '\t') {
                    st = right[k];
                    break;
                }
            }
            if (st == 'h') st = 'H';
            if (st == 't') st = 'T';
            statusArr[n] = st;
            n++;
            if (n >= MAX) break;
        }
    }
    file.close();
}

void urutkanNama() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nama[i] > nama[j]) {
                string tmpN = nama[i];
                nama[i] = nama[j];
                nama[j] = tmpN;
                char tmpS = statusArr[i];
                statusArr[i] = statusArr[j];
                statusArr[j] = tmpS;
            }
        }
    }
}


    cout << "\n===== REKAP KEHADIRAN =====\n";
    cout << "Jumlah Hadir       : " << hadir << "\n";
    cout << "Jumlah Tidak Hadir : " << tidak << "\n";
}
//================================================================//
int cariNama(const string &key) {
    // mengasumsikan data sudah dibaca (bacaFile dipanggil oleh pemanggil)
    for (int i = 0; i < n; i++) {
        if (nama[i] == key) return i;
    }
    return -1;
}
//==================================================================//

void tampilkanAbsen() {
    bacaFile();
    if (n == 0) {
        cout << "Data absensi kosong.\n";
        return;
    }
    urutkanNama();
    cout << "\n===== DAFTAR ABSENSI (URUT A-Z) =====\n";
    for (int i = 0; i < n; i++) {
        cout << i+1 << ". " << nama[i] << " - " << statusArr[i] << "\n";
    }
}

void rekapKehadiran() {
    bacaFile();
    int hadir = 0, tidak = 0;
    for (int i = 0; i < n; i++) {
        if (statusArr[i] == 'H') hadir++;
        else tidak++;
    }

//==================================================================//

void ubahStatus() {
    bacaFile();
    if (n == 0) {
        cout << "Data absensi kosong.\n";
        return;
    }
    string key;
    cout << "Masukkan nama yang ingin diubah: ";
    cin.ignore();
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

    // ini buat nulis ulang file txt nya
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



//============================================================================================//
int main() {
    int pilihan = 0;
    do {
        tampilkanMenu();
        cout << "Pilih menu: ";
        if (!(cin >> pilihan)) {
            cout << "Input tidak valid.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        
        if (pilihan == 1) {
            inputData();
        } else if (pilihan == 2) {
            tampilkanAbsen();
        } else if (pilihan == 3) {
            bacaFile();
            if (n == 0) {
                cout << "Data absensi kosong.\n";
            } else {
                string key;
                cout << "Masukkan nama yang dicari: ";
                cin.ignore(); // bersihkan newline sebelum getline
                getline(cin, key);
                int idx = cariNama(key);
                if (idx != -1) {
                    cout << "Data ditemukan: " << nama[idx] << " - " << statusArr[idx] << "\n";
                } else {
                    cout << "Nama tidak ditemukan.\n";
                }
            }
        } else if (pilihan == 4) {
            rekapKehadiran();
        } else if (pilihan == 5) {
            ubahStatus();
        } else if (pilihan == 6) {
            cout << "Keluar program.\n";
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 6);
    
    return 0;
}
