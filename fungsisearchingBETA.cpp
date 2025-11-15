#include <iostream>
using namespace std;

//Tugas: - Membuat fungsi cariNama() untuk mencari nama tertentu. - Menampilkan hasil pencarian (hadir/tidak hadir).
bool cariNama(const string nama[], int ukuran, const string& namaDicari) {
    for (int i = 0; i < ukuran; i++) {
        if (nama[i] == namaDicari) {
            return true; // Nama ditemukan
        }
    }
    return false; // Nama tidak ditemukan
}
int main() {
    const int ukuran = 5;
    string nama[ukuran] = {"Contoh1", "Contoh2", "Contoh3", "Contoh4", "Contoh5"};
    string namaDicari;

    cout << "Masukkan nama yang ingin dicari: ";
    getline(cin, namaDicari);
    if (cariNama(nama, ukuran, namaDicari)) {
        cout << namaDicari << " hadir dalam daftar." << endl;
    } else {
        cout << namaDicari << " tidak hadir dalam daftar." << endl;
    }

    return 0;
}
