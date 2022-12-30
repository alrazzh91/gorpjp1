#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

typedef
 int matrik[100][100];

int i,j,k,m,n,p,q;

matrik A,B,C;

main()
{
  cout<<"ukuran matrik A : ";
  cin>>m>>n;
  for(i=0;i<m;i++)
   for(j=0;j<n;j++) 
     A[i][j]=rand()%50+1;

  for(i=0;i<m;i++){
    for(j=0;j<n;j++) 
       cout<<A[i][j]<<"\t";
    cout<<endl;
  }
  cout<<"ukuran matrik B : ";
  cin>>p>>q;
  for(i=0;i<p;i++)
   for(j=0;j<q;j++) 
     B[i][j]=rand()%50+1;;

  for(i=0;i<p;i++){
    for(j=0;j<q;j++) 
       cout<<B[i][j]<<"\t";
    cout<<endl;
  }
  if(m==p&&n==q) {
   for(i=0;i<p;i++)
    for(j=0;j<q;j++) 
     C[i][j]=A[i][j]+B[i][j];
  cout<<"Hasil Penjumlahan  :"<<endl; 
  for(i=0;i<m;i++){
    for(j=0;j<n;j++) 
       cout<<C[i][j]<<"\t";
    cout<<endl;
   }
  }
  if(n==p) {
   for(i=0;i<m;i++)
    for(j=0;j<q;j++){
     C[i][j]=0;
     for(k=0;k<n;k++)  
       C[i][j] += A[i][k]*B[k][j];
    }  
  cout<<"Hasil Perkalian  :"<<endl; 
  for(i=0;i<m;i++){
    for(j=0;j<q;j++) 
       cout<<C[i][j]<<"\t";
    cout<<endl;
  }
 }
   for(i=0;i<n;i++)
   for(j=0;j<m;j++) 
     C[i][j]=A[j][i];
  cout<<"Matriks tranpose dari A :"<<endl;
  for(i=0;i<n;i++){
    for(j=0;j<m;j++) 
       cout<<C[i][j]<<"\t";
    cout<<endl;
  }
  
}
