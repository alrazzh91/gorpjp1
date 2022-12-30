#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
using namespace std;

typedef int larik[250000];

long long c=0,ccc,cc=0;
int n,p=0;
larik y;

void cetakdata(larik x,int n)
{int i;

 for (i=0;i<n;i++) {
    cout<<x[i]<<" ";
   }
 cout<<endl;
 cout<<endl;//getch();
}

void tukar(int &a,int &b)
{int t;
  t=a;a=b;b=t;//c++;
}

void sortI(larik x,int n)  // Insertion
{int i,j,a;
    for(int i=1;i<n;i++){
      j=i-1;a=x[i];
      while (j>=0 && x[j]>a)
       { x[j+1]=x[j];j--;//cc++;
       } 
 //      if(j>=0) cc++;
       x[j+1]=a;
 //  cetakdata(x,n);getch();
     }
}
void sortSl(larik x,int n) // Selection
{int min,i,j,temp;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++)
            if(x[j]<x[min]) min=j; 
        temp=x[i];x[i]=x[min];x[min]=temp; //Tukar data   
    }
}
void sortS(larik x,int n) // Sekuensial
{int i,j,t ;
 for (i=0;i<n-1;i++) {
  for (j=i+1;j<n;j++) {
   if (x[i]>x[j]) tukar(x[i],x[j]);
   }
 //  cetakdata(x,n);
  }
}    
void sortB(larik x,int n)  //Bubble
{int i,j,t ;
 for (i=0;i<n-1;i++){
  for (j=0;j<n-1-i;j++) {
   if (x[j]>x[j+1]) tukar(x[j],x[j+1]);}
 //  cetakdata(x,n);
  }
  }


void partisiA(larik x,int aw,int ak,int &j)
{ int i,t,pivot;
   pivot=x[aw];j=aw;//cout<<pivot<<endl;
   for (i=aw+1;i<=ak;i++){//cc++;
     if (x[i]<pivot) {
       j++;t=x[i];x[i]=x[j];x[j]=t;
     }
    } 
  x[aw]=x[j];x[j]=pivot;
 // cetakdata(x,n);
}

void partisi(larik x,int aw,int ak,int &j)
{ int i,t,pivot;
  pivot=x[aw]; i=aw;j=ak;
  while (i<j){
    while ((i<ak)&&(x[i]<=pivot)) i++; 
    while ((j>aw)&&(x[j]>pivot)) j--;  
    if (i<j) {t=x[i];x[i]=x[j];x[j]=t;cc++;}
  }
  x[aw]=x[j];x[j]=pivot;
  cetakdata(x,n);getch();//cout<<cc<<endl;
}
void qsort(larik x,int aw,int ak) //quicksort
{int j;
  if (aw<ak) {
     partisi(x,aw,ak,j);
     qsort(x,aw,j-1);
     qsort(x,j+1,ak);
  }
}


void merge(larik x, int aw,int mid,int ak)
{larik z;  int i,j,k,l;
  i=aw;j=mid+1;k=aw;
  do {cc++;
    if(x[i]<=x[j]) {z[k]=x[i];i++;}
    else {z[k]=x[j];j++;}
    k++;}
  while ((i<=mid) && (j<=ak));
  if (i>mid) for (l=j;l<=ak;l++) {z[k]=x[l];k++;}
  else for (l=i;l<=mid;l++) {z[k]=x[l];k++;}
  for (k=aw;k<=ak;k++) x[k]=z[k]; //cetakdata(x,n);
}
void mergesort(larik x,int aw,int ak)
{int mid;
  if(aw<ak) {
    mid =(aw+ak)/2;
    mergesort(x,aw,mid);
    mergesort(x,mid+1,ak);
    merge(x,aw,mid,ak);
  }
}

void MergeQuick(larik x,int aw,int ak)
{int mid;
  if(ak-aw<60000) qsort(x,aw,ak);
  else {mid =(aw+ak)/2;
    MergeQuick(x,aw,mid);
    MergeQuick(x,mid+1,ak);
    merge(x,aw,mid,ak);
  }
}

void cauntingsort(larik x,int n)
{int t[101]={0},i,j=1;
   for (i=1;i<=n;i++) t[x[i]]++;
   
   for (i=1;i<=100;i++) 
   while (t[i]>=1) {
     x[j]=i;j++;t[i]--;
   }
}

void buatdata(larik x,int &n) // 
{int i;
 cout<<"banyak data :";cin>>n;
 srand(time(NULL));
 for (i=0;i<n;i++) {
    x[i]= rand()%100+1;//y[i]=x[i];
   }
 cout<<endl;
}


int main()
{ int i,j;
  larik x;
  buatdata(x,n);
  cetakdata(x,n);
  clock_t begin_time = clock();
   sortI(x,n); 
   //qsort(x,0,n-1); 
   //mergesort(x,0,n-1);
  cout <<float(clock() - begin_time )/CLOCKS_PER_SEC<<endl;
  cetakdata(x,n);
  //cout<<"\n perbandingan = "<<cc;//<<" B/S = "<<c;
  //cout<<"\n Banyak Tukar = "<<c;//<<" B/S = "<<c;
 return 0;
}

