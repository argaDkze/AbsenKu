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
