#include<iostream>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<iomanip>

using namespace std;

int main() {
   int i,j,a,k=0,l,c,n,max,min,t[101]={0};
   double sd,sum,sum1,rerata;
  // for (i=0;i<=100;i++) {
  //  cout<<t[i]<<" ";
  //  if((i+1)%20==0) cout<<endl;
  // }
   cout<<"masukkan banyak data : ";cin>>n;
   int x[n];
   srand(time(NULL));
 /*  for(i=0;i<n;i++) {
    x[i]=rand()%100+1;
    cout<<x[i]<<" ";
    if ((i+1)%10==0) cout<<endl;
    }
*/
    for(int i=0;i<n;i++){
     j=i-1;a=rand()%100+1;
     while (j>-1 && x[j]>a) { x[j+1]=x[j];j--;} 
     x[j+1]=a;
    } 
    for(i=0;i<n;i++) {
      cout<<x[i]<<" ";
      if ((i+1)%10==0) cout<<endl;
    }
   cout<<endl;
   max=min=x[0]; 
   for (i=1;i<n;i++)
      if (x[i]>max) max=x[i];else
        if(x[i]<min) min=x[i]; 
   cout<<"data max adalah : "<<max<<endl;
   cout<<"data min adalah : "<<min<<endl; 
   getch(); 

   sum=0;
   for(i=0;i<n;i++) sum+=x[i];
   rerata= sum/n;
   cout<<"rata-rata = "<<setprecision(8)<<rerata<<" ";
   
   sum1=0;
   for(i=0;i<n;i++) sum1+=pow((x[i]-rerata),2);
   sd= sqrt(sum1/(n-1));
    
   cout<<"dengan standar deviasi = "<<sd;
   cout<<endl;
   
   cout<<"data yang duplikasi :"<<endl;

   for (i=0;i<n;i++) t[x[i]]++;
    
   for (i=1;i<=100;i++) 
     if (t[i]>1) cout<<i<<" "<<t[i]<<endl;    
   cout<<endl;  
   cout<<"modus : ";
   max=t[1];
   for (i=2;i<=100;i++) if(t[i]>max) max=t[i];
   if (max<=1) cout<<"Tidak ada modus ";
   else  
     for (i=1;i<=100;i++) if (t[i]==max) cout<<i<<", ";
   cout<<"\n frekuensi maksimum = "<<max;
   return 0; 
}

