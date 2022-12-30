#include<iostream>
#include<math.h>
#include<conio.h>

using namespace std;

typedef int larik[150001];

int t,s=0;

void BuatDataBeda(int x[200001],int &n)
{ int i,j;bool ada;
  cout<<"banyak data : ";cin>>n;
  srand(1560382597);//time(NULL));
  for (i=1;i<=n;i++) {
    do {   
        x[i]=rand()%100+1;
        j=i-1;ada=false;
        while (j>=1){ 
           if (x[i]==x[j]) {
              ada=true;j=0;
           } else j--;
         }
     } while (ada);
     
     cout<<x[i]<<" ";
  }
}    

long prima(int N)
{long p;
 bool prima;
 do {
  if ((N==2)||(N==3)) prima=true;
  else if ((N%2==0)||(N<2)) prima=false;
       else
       { p=3;prima=true;
	      do {
	         if ((N%p)==0)  prima=false; else p=p+2;
	        }
	      while ( prima && p<=(sqrt(N)+1));
       }
   if (!prima) N++;    
 } while (!prima);
 return N;
}

void hashing(int X[200001],int N,larik H)
{ int IH,I,p,j=0;int temp[10];
  p=prima(N);
  //p=15;
  for(int i=0;i<p;i++) {
    H[i]=0;
  }
  for(int i=1;i<=N;i++) {
      IH = X[i]%p;
      if (H[IH]==0) H[IH]=X[i];
      else {
        temp[j]=X[i];j++;   
      }
   }
   cout<<endl;
   for (int I=0;I<p;I++) {
     cout<<I<<"  "<<H[I]<<" ";
     if (H[I]!=0) s++;
     cout<<endl;
   }
   cout<<"Temp = ";
   for (int I=0;I<j;I++) {
     cout<<temp[I]<<" ";
   }
   int m=j;
   for (int i=0;i<m;i++) {
      IH = temp[i]%p;j=++IH%p;t=2;
      while (j<p && H[j%p]!=0) {j=++j%p;t++;}
      H[j%p]=temp[i];s+=t;
   }
   cout<<endl;
   for (int I=0;I<p;I++) {
     cout<<I<<"  "<<H[I]<<" ";
     cout<<endl;
   }
}

void cari(larik H,int N)
{int lokasi,a,i,j,p,IH;bool ada;
  cout<<"\nmasukkan data yg dicari : ";cin>>a;
   p=prima(N);
   //p=15;
   i=a % p;ada=false;
   if ((H[i]==a) && (a!=0)) {ada=true;lokasi=i;}
   else {
      j=++i%p;
      while (H[j]!=0 && H[j%p]!=a) {j=++j%p;}
      if(H[j%p]==a) {ada=true;lokasi=j%p;}
   }
   if (ada) cout<<"data ada di "<<lokasi;
   else cout<<"data tidak ada";
}
    

int main()
{ int x[200001],n;larik H;
  BuatDataBeda(x,n);
  cout<<endl;
  getch();
  hashing(x,n,H);
  cout<<endl;getch();
  cout<<"rata-rata : "<<(float)s/n;
  cari(H,n);
  return 0;
}


