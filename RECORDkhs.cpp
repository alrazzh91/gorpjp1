#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
struct matkul{
     string kode;
     int sks;
     char nilai;
  };

typedef matkul larik[100];
matkul ma,mb;
int n,i,j,bobot;
larik x;char c;
float t=0,ts=0,ip;

void sortI(larik x,int n)
{int i,j;matkul a;
    for(int i=2;i<=n;i++){
      j=i-1;a=x[i];
      while (j>0 && x[j].kode>a.kode)
       { x[j+1]=x[j]; //menyamakan 2 variabel struct; 
         j--;
       } 
       x[j+1]=a;
     }
}

int main(){
 cout<<"banyak matakuliah : ";cin>>n; 
 srand(time(NULL));     
 for (i=1;i<=n;i++) {
   x[i].kode="MII ";
   for (j=1;j<=4;j++) {
     if (j==1) c=49+rand()%3; else c=48+rand()%10; 
     x[i].kode+=c;;
   }  
   x[i].sks=rand()%3+1;
   x[i].nilai=65+rand()%2;
 //  cout<<x[i].kode<<" "<<x[i].sks<<"  "<<x[i].nilai<<endl;
 }
 for (i=1;i<=n;i++) {
      bobot=4-(x[i].nilai-65);//konversi dari nilai huruf ke bobot
      t+=x[i].sks*bobot;
      ts+=x[i].sks;
  }   
  ip=(float)t/ts;    
  sortI(x,n);
  cout<<"kode MK  sks  nilai"<<endl;
   for (i=1;i<=n;i++) {
   cout<<x[i].kode<<"   "<<x[i].sks<<"  "<<x[i].nilai<<endl;
 }
  cout<<"IP  ="<<ip<<endl;
  return 0;
}




