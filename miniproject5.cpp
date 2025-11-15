#include <iostream>
using namespace std;

// untuk deklarasi ukuran data
const int JUMLAH_SISWA = 6;

// untuk deklarasi array absensi (H = Hadir, A = Alpha / tidak hadir)
char absensi[JUMLAH_SISWA] = {'H', 'A', 'H', 'H', 'H', 'H'};
string namaSiswa[JUMLAH_SISWA] = {"Arga", "Wenno", "Bintang", "Rafi", "Zalika", "Dinda"};

// fungsi untuk menampilkan data absensi
void tampilkanAbsen()
{
    cout << "=== Data Absensi ===" << endl;
    for (int i = 0; i < JUMLAH_SISWA; i++)
    {
        cout << i + 1 << ". " << namaSiswa[i] << " : "
             << (absensi[i] == 'H' ? "Hadir" : "Tidak Hadir") << endl;
    }
}

// Fungsi untuk menghitung rekap kehadiran
void rekapKehadiran()
{
    int hadir = 0, tidak_hadir = 0;

    for (int i = 0; i < JUMLAH_SISWA; i++)
    {
        if (absensi[i] == 'H')
        {
            hadir++;
        }
        else
        {
            tidak_hadir++;
        }
    }

    cout << "\n=== Rekapitulasi Kehadiran ===" << endl;
    cout << "Jumlah Hadir       : " << hadir << endl;
    cout << "Jumlah Tidak Hadir : " << tidak_hadir << endl;
}

int main()
{
    tampilkanAbsen();
    rekapKehadiran();

    return 0;
}
