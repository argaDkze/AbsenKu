void ubahStatus() {
    bacaFile();
    if (n == 0) {
        cout << "Data absensi kosong." << endl;
        return;
    }
    string key;
    cout << "Masukkan nama yang ingin diubah: ";
    cin >> key;
    int idx = cariNama(key);
    if (idx == -1) {
        cout << "Nama tidak ditemukan.\n";
        return;
    }
    cout << "Status saat ini: " << statusArr[idx] << endl;
    char baru;
    cout << "Masukkan status baru (H/T): ";
    cin >> baru;
    if (baru != 'H' && baru != 'T' && baru != 'h' && baru != 't') {
        cout << "Input status tidak valid. Perubahan dibatalkan." << endl;
        return;
    }
    if (baru == 'h') baru = 'H';
    if (baru == 't') baru = 'T';
    statusArr[idx] = baru;

    ofstream file("absensi.txt", ios::trunc);
    if (!file) {
        cout << "Gagal membuka file untuk menulis." << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        file << nama[i] << " " << statusArr[i] << endl;
    }
    file.close();
    cout << "Status berhasil diperbarui dan file disimpan." << endl
}