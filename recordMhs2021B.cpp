#include <iostream>    
using namespace std;
	struct mahasiswa { 
	    char nim[5]; 
	    string nama;  
	    float ipk;  
	} ;  
int main(){ int n;
    mahasiswa mhs; cin>>n;cin.ignore();
	cout<<"Masukkan NIM : ";  
	gets(mhs.nim); 
	cout<<"Masukkan Nama : ";  
	getline(cin,mhs.nama);  
	cout<<"Masukkan IPK : ";  
	cin>>mhs.ipk;    
	cout<<"Data mahasiswa yang dimasukkan : "<<endl;  
	cout<<"NIM Mahasiswa : "<<mhs.nim<<endl;  
	cout<<"Nama Mahasiswa : "<<mhs.nama<<endl;  
	cout<<"IPK Mahasiswa : "<<mhs.ipk;       
	return 0;   
}

  
  
