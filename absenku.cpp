//Bintang bintuy
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

// Struktur untuk menyimpan data per siswa
struct Siswa
{
    string nama;
    string status; // Hadir, Sakit, Izin, Alpha
    string alasan;
};

// 1. FUNGSI: Input Data Absensi
vector<Siswa> inputAbsensi(int jumlahSiswa)
{
    vector<Siswa> daftarSiswa;

    // Membersihkan buffer dari input jumlahSiswa di main()
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n=================================================" << endl;
    cout << "                   INPUT ABSENSI" << endl;
    cout << "=================================================" << endl;

    // --- LOOP untuk Input Data ---
    for (int i = 0; i < jumlahSiswa; ++i)
    {
        Siswa s;
        string statusInput;

        // Input Nama (menggunakan getline untuk nama lengkap)
        cout << "Nama Siswa ke-" << i + 1 << ": ";
        getline(cin, s.nama);

        // Input Kehadiran
        cout << "Status (" << s.nama << ") (H/S/I/A): ";
        cin >> statusInput;

        // PERBAIKAN PENTING: Membersihkan buffer setelah cin >> statusInput
        // Karakter 'Enter' (\n) yang tersisa harus dihapus sebelum getline berikutnya.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // --- PERCABANGAN untuk Status dan Alasan ---
        if (statusInput == "H" || statusInput == "h")
        {
            s.status = "Hadir";
            s.alasan = "-";
        }
        else if (statusInput == "S" || statusInput == "s" || statusInput == "I" || statusInput == "i")
        {
            if (statusInput == "S" || statusInput == "s")
            {
                s.status = "Sakit";
            }
            else
            {
                s.status = "Izin";
            }
            // Minta Alasan jika Sakit atau Izin
            cout << "Masukkan Alasan " << s.status << ": ";
            getline(cin, s.alasan);
        }
        else
        {
            s.status = "Alpha";
            s.alasan = "Tanpa Keterangan";
        }

        daftarSiswa.push_back(s); // Tambahkan ke array (vector)
        cout << "-------------------------------------------------" << endl;
    }
    return daftarSiswa;
}

// 2. FUNGSI: Menampilkan Rekapitulasi
void tampilkanRekap(const vector<Siswa> &data)
{
    cout << "\n=================================================" << endl;
    cout << "               REKAPITULASI ABSENSI" << endl;
    cout << "=================================================" << endl;
    cout << "No. | Nama Siswa\t| Status\t| Alasan" << endl;
    cout << "-------------------------------------------------" << endl;

    // --- LOOP untuk Rekapitulasi ---
    for (size_t i = 0; i < data.size(); ++i)
    {
        cout << i + 1 << ".  | ";
        cout << data[i].nama << "\t| ";

        // Percabangan untuk penataan output (agar kolom rata)
        // Dibuat lebih sederhana: menggunakan tab jika nama cukup pendek
        if (data[i].status.length() < 6)
        {
            cout << data[i].status << "\t\t| ";
        }
        else
        {
            cout << data[i].status << "\t| ";
        }

        cout << data[i].alasan << endl;
    }

    cout << "=================================================" << endl;
}

// FUNGSI UTAMA (Main Function)
int main()
{
    int jumlahSiswa;

    cout << "Masukkan total jumlah siswa: ";
    if (!(cin >> jumlahSiswa) || jumlahSiswa <= 0)
    {
        cout << "Input tidak valid. Program dihentikan." << endl;
        return 1;
    }

    // Panggil FUNGSI inputAbsensi dan simpan hasilnya
    vector<Siswa> hasilAbsensi = inputAbsensi(jumlahSiswa);

    // Panggil FUNGSI tampilkanRekap untuk mencetak hasil
    tampilkanRekap(hasilAbsensi);

    return 0;
}
