#include<iostream>
#include<math.h>
using namespace std;
typedef int Larik[100];
 Larik X;
 int i,j;

void BuatData(Larik X,int N)
{ for (i=1;i<=N;i++) {
     X[i]=i+3*i*i; cout<<X[i]<<" ";
   } cout<<endl;
}
int Apaan(int a,int b){
	return (2*a+pow(b,2));
}
int Apaan(Larik X,int N,int k)
{ int mid;
  mid = (1+N)/2;
  switch (k) {
      case 1 : {return X[(1+mid-1)/2]*2/3;break;}
      case 2 : {return X[mid]/2;break;}
      case 3 : {return X[(mid+1+N)/2]*3/4;break;}
   }
}
int main() {
    int N=10;float a=2;
    BuatData(X,N);
    cout<<Apaan(X,N,1)<<" "<<Apaan(X,N,2)<<" "<<Apaan(X,N,3)<<endl;
    cout<<Apaan(a,5);
    return 0;
}
