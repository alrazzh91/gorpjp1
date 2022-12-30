#include <iostream>    
using namespace std;	  
int main(){  
	struct {  
	    string nim,nama;  
	    float ipk;  
	} mhs;
	cout<<"Masukkan NIM : ";  
	getline(cin,mhs.nim); 
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


  
  
