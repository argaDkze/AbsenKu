#include <iostream>
#include <fstream>

const int MAX = 100;

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

void urutkanNama(string nama[], char status[], int jumlah){
  string tempNama;
  char tempStatus;
  
  for(int i = 0;i < jumlah -1; i++){
    for(int j = 0;j < jumlah - i - 1; j++){
      if (nama[j] > nama[j+1]){
        tempNama = nama[j];
        nama[j] = nama[j+1];
        nama[j+1] = tempNama;
        
        tempStatus = status[j];
        nama[j] = nama[j+1];
        nama[j+1] = tempStatus;
      }
    }
}