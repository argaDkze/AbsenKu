#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Fungsi untuk input data absensi
void inputData() {
    string nama;
    char status;
    ofstream file("absensi.txt", ios::app); // mode append agar data baru tidak menimpa data lama

    if (!file.is_open()) {
        cout << "Gagal membuka file!" << endl;
        return;
    }

    cout << "Masukkan nama mahasiswa: ";
    getline(cin, nama);

    // Validasi input status
    do {
        cout << "Masukkan status (H = Hadir / T = Tidak Hadir): ";
        cin >> status;
        status = toupper(status); // ubah ke huruf besar
        if (status != 'H' && status != 'T') {
            cout << "Input tidak valid! Ulangi lagi.\n";
        }
    } while (status != 'H' && status != 'T');

    // Simpan ke file
    file << nama << " - " << status << endl;
    file.close();

    cout << "Data berhasil disimpan ke absensi.txt!" << endl;
}

int main() {
    cin.ignore(); // untuk menghindari bug input getline
    inputData();
    return 0;
}
