#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//batas data
const int MAX = 100;
//baca file absen.txt lalu simpan nama dan status ke array(h/t)
void bacaFile(string nama[], char status[], int &jumlah){
  ifstream file("absensi.txt");
  jumlah = 0;
  
  if (!file.is_open()){
    cout << "File tidak bisa dibuka";
    return;
  }
  while(file >> nama[jumlah] >> status[jumlah]){
    jumlah++;
  }
  file.close();
}
//urutkan array nama menggunakan bubble sort dan untuk menukar status(h/t)
void urutkanNama(string nama[], char status[], int jumlah){
  string tempNama;
  char tempStatus;
  
  for(int i = 0;i < jumlah -1; i++){
    for(int j = 0;j < jumlah - i - 1; j++){
      if (nama[j] > nama[j+1]){
        //tukar nama
        tempNama = nama[j];
        nama[j] = nama[j+1];
        nama[j+1] = tempNama;
        //tukar status
        tempStatus = status[j];
        status[j] = status[j+1];
        status[j+1] = tempStatus;
      }
    }
  }
}

//fungsi main
int main(){
  string nama[MAX];
  char status[MAX];
  int jumlah;
  //baca file
  bacaFile(nama, status, jumlah);
  // urutkan nama
  urutkanNama(nama, status, jumlah);
  //menampilkan hasil
  cout << " Data setelah diurutkan: " << '\n';
  for(int i=0;i < jumlah; i++){
    cout << nama[i] << " - " << status[i] << '\n';
  }
  return 0;
}
