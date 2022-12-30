#include <iostream>   
using namespace std;
 struct mahasiswa {  
         string nim,nama;  
         float ipk;  
  };  
int main(){  
  int i,n;  
  cout<<"Banyak data mahasiswa :"; cin>>n; 
  mahasiswa mhs[n];
  for (i=0;i<n;i++){  
      cout<<"Mahasiswa ke - "<<i+1<<": "<<endl;  
      cout<<"Masukkan NIM : ";cin.ignore();
	  getline(cin,mhs[i].nim);  
      cout<<"Masukkan Nama : ";
      getline(cin,mhs[i].nama);   
      cout<<"Masukkan IPK : ";  
      cin>>mhs[i].ipk;     
  }   
  cout<<"Data mahasiswa yang dimasukkan : "<<endl;  
  for (i=1;i<=n;i++) {  
      cout<<"Mahasiswa ke - "<<i<<": "<<endl;  
      cout<<"NIM : "<<mhs[i-1].nim<<endl;  
      cout<<"Nama : "<<mhs[i-1].nama<<endl;  
      cout<<"IPK : "<<mhs[i-1].ipk<<endl;   
      cout<<endl;  
  }      
  return 0;   
}  

