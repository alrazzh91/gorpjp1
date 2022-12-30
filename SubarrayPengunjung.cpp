#include<iostream>
#include<time.h>

using namespace std;
typedef int larik[100];

void bacadata(larik x,int &n){
   int r;
   cout<<"masukkan banyak data : "; cin>>n;
   x[0]=2;
   srand(time(NULL));
   for (int i=1;i<n;i++) {
      r=rand()%15;
      x[i]=x[i-1]+r;
	}	
}
void cetakdata(larik x,int n){
   for (int i=0;i<n;i++) {
      cout<<x[i]<<" ";
	}	
	cout<<endl;
}
void tumbuh(larik x,int n){
   for (int i=n-1;i>0;i--) {
      x[i]=x[i]-x[i-1];
 	}	
}
int main() {
    int i,r,n;
    larik x;
    bacadata(x,n);
    cetakdata(x,n);
    tumbuh(x,n);
    cetakdata(x,n); 
	return 0;	
}

