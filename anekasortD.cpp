#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
using namespace std;

long long c=0, *z,n,cc=0,p=0;

void buatdata(long long *x,int &n)
{int i;
 cout<<"banyak data :";cin>>n;
 srand(time(NULL));
 for (i=1;i<=n;i++) {
    x[i]= rand()*1000+1;
 cout<<x[i]<<" ";
   }
 cout<<endl;
 cout<<endl;
}
void sortS(long long *x,int n)
{int i,j,t ;
 for (i=0;i<n-1;i++)
  for (j=i+1;j<n;j++) 
   if (x[i]>x[j]) {t=x[i];x[i]=x[j];x[j]=t;}
  }
void sortB(long long *x,int n)
{int i,j,t ;
 for (i=0;i<n-1;i++)
  for (j=0;j<n-1-i;j++) 
   if (x[j]<x[j+1]) {t=x[j];x[j]=x[j+1];x[j+1]=t;}
  }

void sortI(long long *x,int n)
{int i,j,a;
    for(int i=1;i<n;i++){
      j=i-1;a=x[i];
      while (j>=0 && x[j]>a)
       { x[j+1]=x[j];  j--;
       } 
       x[j+1]=a;
     }
}
void sortSl(long long *x,int n) // Selection
{int min,i,j,temp;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++)
            if(x[j]<x[min]) min=j; 
        temp=x[i];x[i]=x[min];x[min]=temp;    
    }
}
void sortI1(long long *x,int aw,int ak)
{int i,j,a;
    for(int i=aw+1;i<=ak;i++){
      j=i-1;a=x[i];
      while (j>0 && x[j]>a)
       { x[j+1]=x[j];  j--;
       } 
       x[j+1]=a;
     }
}
void cetakdata(long long *x,int n)
{int i;
 for (i=0;i<n;i++) {
    cout<<x[i]<<" ";
   }
 cout<<endl;
 cout<<endl;getch();
}
void partisiM3(long long *x,int aw,int ak,int &j)
{ int i,t,mid,pivot;
   mid=(aw+ak)/2;
   if(x[aw]>x[mid]) {t=x[aw];x[aw]=x[mid];x[mid]=t;}
   if(x[aw]>x[ak]) {t=x[aw];x[aw]=x[ak];x[ak]=t;}  
   if(x[mid]>x[ak]) {t=x[mid];x[mid]=x[ak];x[ak]=t;}
   {t=x[aw];x[aw]=x[mid];x[mid]=t;}
   pivot=x[aw];
   j=aw;
   for (i=aw+1;i<=ak;i++)
     if (x[i]<pivot) {
       j++;t=x[i];x[i]=x[j];x[j]=t;
     }
  x[aw]=x[j];x[j]=pivot;
}
void partisiA(long long *x,int aw,int ak,int &id)
{ int i,j,t,pivot;
   pivot=x[aw];j=aw;
   for (i=aw+1;i<=ak;i++)
     if (x[i]<pivot) {
       j++;t=x[i];x[i]=x[j];x[j]=t;
     }
  x[aw]=x[j];x[j]=pivot;
  id=j;
}
void partisiB(long long *x,int aw,int ak,int &id)
{ int i,j,t,pivot;
   pivot=x[aw];j=aw;
   i=aw+1;
   while(i<=ak) {
     if (x[i]<pivot) {
       j++;t=x[i];x[i]=x[j];x[j]=t;
     }
     i++;
   }
  x[aw]=x[j];x[j]=pivot;
  id=j;
}
void partisiAR(long long *x,int aw,int ak,int &id)
{ int i,r,j,t,pivot;
   r=rand()%(ak-aw+1)+aw;
   pivot=x[r];x[r]=x[aw];x[aw]=pivot;
   j=aw;
   for (i=aw+1;i<=ak;i++)
     if (x[i]<pivot) {
       j++;t=x[i];x[i]=x[j];x[j]=t;
     }
  x[aw]=x[j];x[j]=pivot;
  id=j;
}
void partisi(long long *x,int aw,int ak,int &j)
{ int i,t,pivot;
  pivot=x[aw];
  i=aw;j=ak;
  while (i<j){
    while ((i<ak)&&(x[i]<=pivot)) i++;
    while ((j>aw)&&(x[j]>pivot)) j--;  
    if (i<j) {t=x[i];x[i]=x[j];x[j]=t;}
  }
  x[aw]=x[j];x[j]=pivot;
  //cetakdata(x,n);
}
void qsort(long long *x,int aw,int ak)
{int j;
  if (aw<ak) {
     partisi(x,aw,ak,j);
     qsort(x,aw,j-1);
     qsort(x,j+1,ak);
  }
}

void merge(long long *x,int aw,int mid,int ak)
{ int i,j,k,l;
  i=aw; j=mid+1;  k=aw;
  do {p++;
    if(x[i]<=x[j]) {z[k]=x[i];i++;}
    else {z[k]=x[j];j++;}
    k++;}
  while ((i<=mid) && (j<=ak));
  if (i>mid) for (l=j;l<=ak;l++) {z[k]=x[l];k++;}
  else for (l=i;l<=mid;l++) {z[k]=x[l];k++;}
  for (k=aw;k<=ak;k++) x[k]=z[k];
  cetakdata(x,n);
}
void mergesort(long long *x,int aw,int ak)
{int mid;
  if(aw<ak) {
    mid =(aw+ak)/2;
    mergesort(x,aw,mid);
    mergesort(x,mid+1,ak);
    merge(x,aw,mid,ak);
  }
}
void mergesort1(long long *x,int aw,int ak)
{int mid;
 // if(ak-aw<5) sortI1(x,aw,ak); else
  {
    mid =(aw+ak)/2;
    mergesort(x,aw,mid);
    mergesort(x,mid+1,ak);
    merge(x,aw,mid,ak);
  }
}

void MergeQuick(long long *x,int aw,int ak)
{int mid;
  if(ak-aw<50000) qsort(x,aw,ak);
  else {
    mid =(aw+ak)/2;
    MergeQuick(x,aw,mid);
    MergeQuick(x,mid+1,ak);
    merge(x,aw,mid,ak);
  }
}
void create_heap(long long *a,int n)
{
int q,i,j,key;
  for(q=2;q<=n;q++)
  {
    i=q;
    key=a[i];
    j=i/2;
    while(i>1 && key>a[j])
      {
         a[i]=a[j];
         i=j;
         j=i/2;
         if(j<1)
            j=1;
      }
    a[i]=key;
    }
}

void sort_heap(long long *a,int n)
{
int q,i,j,key,temp;
  create_heap(a,n);
  for(q=n;q>=1;q--)
  {
     temp=a[1];
     a[1]=a[q];
     a[q]=temp;
     i=1;
     key=a[i];
     j=2*i;
     if(j+1 < q)
     {
         if(a[j+1] > a[j])
            j++;
        }
     while(j<=q-1 && key<a[j])
     {
       a[i]=a[j];
       i=j;
       j=2*i;
       if(j+1 < q)
       {
          if(a[j+1] > a[j])
             j++;
       }
       else break;
     }
     a[i]=key;
    }
}

void countingsort(long long *x,int n)
{int t[1001]={0},i,j=1;
   for (i=1;i<=n;i++) t[x[i]]++; 
   for (i=1;i<=1000;i++) 
     while (t[i]>=1) {
       x[j]=i;j++;t[i]--;
   }
}
int main()
{ long long i,j,*x,t;
  cout<<"banyak data :";cin>>n;
  x=new long long[n]; //ARRAY DINAMIS
  z=new long long[n];
  cout<<sizeof(x)<<endl;
  srand(time(NULL));
  for (i=0;i<n;i++) {
  	t=rand();
    x[i]= t*6500000+1;
    x[i]= rand()%100+1;
    }
  sortB(x,n);
  cetakdata(x,n);
  clock_t begin_time = clock();
    //qsort(x,0,n-1);
   // MergeQuick(x,0,n-1);

     mergesort(x,0,n-1);
    //sortI(x,n);
   cout << float( clock () - begin_time )/CLOCKS_PER_SEC;
   cetakdata(x,n);
  cout<<"\n perbandingan = "<<p;
 return 0;
}
