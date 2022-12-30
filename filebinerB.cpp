#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>

using namespace std;

 typedef struct {
            char kode[10];
            int harga;
            int jumlah; 
        } barang;
long p=0;
 
void filebaru(char namafile[20])
{ barang b;
  ofstream f; 
  f.open(namafile,ios::out|ios::binary);
  if (f.is_open())
  {  
      cout<<"kode   : ";cin>>b.kode;
      cout<<"harga  : ";cin>>b.harga;
      cout<<"jumlah : ";cin>>b.jumlah;     
      f.write((char*)&b, sizeof(barang));
  }
  else cout<<"error..";
  cin.get();
  f.close(); 
}

void TambahEditData(char namafile[20])
{ barang b;char kd[10];
  int jml;
  fstream f; 
  f.open(namafile,ios::in|ios::out|ios::ate|ios::binary);
  if (f.is_open()){  
      cout<<"kode barang :";cin>>kd;
      f.seekg(0);p=0;
      do {p++;
         f.read((char*)&b, sizeof (barang));
         }
      while ((!f.eof()) && (strcmp(b.kode,kd)!=0));      
      if (strcmp(b.kode,kd)==0) {
          cout<<"\n"<<b.kode<<"  "<<b.harga<<"   "<<b.jumlah<<endl;
          cout<<"jumlah barang : ";cin>>jml;
          b.jumlah +=jml;
          f.seekp((p-1)*sizeof(barang));
          f.write((char*)&b, sizeof(barang));
          f.close(); 
          }
      else {
         ofstream f(namafile,ios::app|ios::binary);
         cout<<"data baru"<<endl;      
         strcpy(b.kode,kd);
         cout<<"harga  : ";cin>>b.harga;
         cout<<"jumlah : ";cin>>b.jumlah;
         f.write((char*)&b, sizeof(barang));
    }       
  }
  else cout<<"error";
  cin.get();
}

void DeleteData(char namafile[20])
{ barang b,br;char kd[10];
  int jml;
  fstream f; 
  ofstream g; 
  f.open(namafile,ios::in|ios::out|ios::ate|ios::binary);
  if (f.is_open()) {
      cout<<"kode barang yang akan dihapus :";cin>>kd;
      f.seekg(0);p=0;
      do {p++;
         f.read((char*)&b, sizeof (barang));
         }
      while ((!f.eof()) && (strcmp(b.kode,kd)!=0));      
      if (strcmp(b.kode,kd)==0) {
          cout<<"\n"<<b.kode<<"  "<<b.harga<<"   "<<b.jumlah<<endl;         
          cin.get();
          g.open("temp.bin",ios::out|ios::binary);
          f.seekg(0);
          while (f.read((char*)&br, sizeof (barang))) {
             if(strcmp(br.kode,b.kode)!=0) g.write((char*)&br, sizeof (barang));
           }
 		  g.close();  
          f.close(); 
          remove(namafile);
          rename("temp.bin",namafile);
           }
      else {
         cout<<"Data tidak ada ";
         cin.get();
    }       
  }
  else cout<<"error";
  cin.get();
}

void search(char namafile[20])
{ barang b;
  int i,j,n;
  char kd[10];
  ifstream f; 
  f.open(namafile,ios::in|ios::binary);
  if (f.is_open())
  { 
      cout<<"kode barang yg dicari :";cin>>kd;
      f.seekg(0);
      do {
         f.read((char*)&b, sizeof (barang));
         }
      while ((!f.eof()) && (strcmp(b.kode,kd)!=0));      
      if (strcmp(b.kode,kd)==0) {
          cout<<"\n"<<b.kode<<"  "<<b.harga<<"   "<<b.jumlah<<endl;
          f.close(); 
          }
      else 
         cout<<"data tidak ada"<<endl;      
    }
  else cout<<"error";
  cin.get();               
}

void bacafile(char namafile[20])
{ barang b;
  ifstream f;int i=0; 
  f.open(namafile,ios::in|ios::binary);
  if (f.is_open())
  {   f.seekg(0);
      system ( "CLS" );
      while(!f.eof()){
         i++;
         f.read((char*)&b, sizeof (barang));
         if (!f.eof()) cout<<i<<". "<<b.kode<<"  "<<b.harga<<"   "<<b.jumlah<<endl;
      }
  }
  else cout<<"error";
  cin.get();
  f.close(); 
}

int main() {
 //filebaru("barangZ.bin");
 bacafile("barangZ.bin");
// TambahEditData("barangZ.bin");
// bacafile("barangZ.bin");
// search("barangZ.bin");
 //DeleteData("barangZ.bin");
// bacafile("barangZ.bin");
 return 0;
}
