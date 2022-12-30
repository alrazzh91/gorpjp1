#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<math.h>
using namespace std;
typedef int larik[100000];
int i,j;
long long sum;
void bacadata(larik x,int &n)
{ srand(time(NULL));
  cout<<"banyak data :";cin>>n;
  for (i=1;i<=n;i++) {
    x[i]=rand()%100+1;
  }
}
float rerata(larik x,int n)
{ sum=0;
  for (i=1;i<=n;i++) sum+=x[i];
  return (float)sum/n;
}
float SD(larik x,int n){
  sum=0;float rata=rerata(x,n);
  for(i=1;i<=n;i++) sum+=pow((x[i]-rata),2);
   return sqrt(sum/(n-1));
}
int max(larik x,int n){
 int maks=x[1];
 for(i=2;i<=n;i++)
   if(x[i]>maks) maks=x[i];
 return maks;
}     
void cetak(larik x,int n)
{ for(i=1;i<=n;i++) {
     cout<<x[i]<<" ";
     if(i%20==0) cout<<endl;    
  }
  cout<<"\n";
  getch();
}
void tukar(int &a,int &b)
{int t;
  t=a;a=b;b=t;
}
void sort(larik x,int n){
 for (i=1;i<=n-1;i++)
  for (j=i+1;j<=n;j++) 
   if (x[i]>x[j]) tukar(x[i],x[j]);
}    
void modus(larik X,int n)
{larik Y,F;
 int m,maks,k=0;
   for (i=1;i<=n;i++) F[i]=1; //memberi nilai awal F
   j=1; X[n+1]=X[n]+1;
   for (i=1;i<=n;i++)
     if (X[i]==X[i+1]) F[j]++;else {Y[j]=X[i];j++;}
   m=j-1;
   maks=max(F,m);
   if (maks==1) cout<<"tidak ada modus";
    else {
      cout<<"modusnya adalah : ";
      for (i=1;i<=m;i++) {
	     if (F[i]==maks) cout<<Y[i]<<", ";
      }
    }
   getch();
 }

int main()
{ larik x;int n;
  bacadata(x,n);
  cetak(x,n);
  cout<<"maximum = "<<max(x,n)<<endl;
  cout<<"\nrerata = "<<rerata(x,n);
  cout<<"\nstandar deviasi = "<<SD(x,n)<<endl;
  cout<<"\nData setelah diurutkan :"<<endl;
  sort(x,n);
  cetak(x,n);
  modus(x,n);  
  return 0;
}

