#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int main() {
  char c,jawab;
  string strg,nama;
  int i=0,nilai=0;
  cout<<"Nama anda : ";getline(cin,nama); 
  ifstream f;
  f.open("SOALB.TXT");
  if (f.is_open())
  {
    while (!f.eof()) {
      system ("CLS");
      i++;cout<<i<<". ";
      do {    
         getline(f,strg);
         if (strg[0]!='*') cout<<strg<<endl;
       }
      while (strg[0]!='*');
      cout<<endl;
      cout<<"Jawabanmu (a,b,c atau d) : ";cin>>jawab;
      cout<<endl;
      if (toupper(jawab)==strg[1]) {
             cout<<"Hebat anda...benar\n";nilai+=10;}
       else {
              cout<<"Belum Hebat anda...salah tahu!\n";nilai-=5;}  
      getch();
      }
     cout<<endl; 
     cout<<"Nilai akhir Anda adalah : "<<nilai;  
     ofstream g;
     g.open("nilaiC.txt",ios::app);
     g<<nama<<" "<<nilai<<"\n";
     g.close();
  }
  else cout<<"error..file not found";
  getch();
  f.close();
  return 0;
}
