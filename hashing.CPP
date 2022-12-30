#include<iostream>
#include<math.h>
#include<conio.h>
#include<time.h>

using namespace std;

typedef struct node
         { int data;
           struct node *next;
           } *list;
typedef struct node larik[15001];

int s=0;

void BuatDataBeda(int x[20001],int &n)
{ int i,j;bool ada;
  cout<<"banyak data : ";cin>>n;
  srand(time(NULL));
  for (i=0;i<n;i++) {
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

void hashing(int X[20001],int N,larik H)
{ int IH,I,p,t;list Q,b;
  p=prima(N);
  for(int i=0;i<p;i++) {
    H[i].data=0;H[i].next=NULL;
  }
  for(int i=0;i<N;i++) {
      IH = X[i]%p;
      if (H[IH].data==0) H[IH].data=X[i];
      else {
        b=new node;b->data=X[i];b->next=NULL;
        if (H[IH].next==NULL) H[IH].next=b; 
        else {
           Q=H[IH].next;
           while (Q->next!=NULL) Q=Q->next;
           Q->next=b;
        }          
      }
   }
   cout<<endl;
   for (int I=0;I<p;I++) {
     cout<<I<<"  "<<H[I].data<<" ";
     if (H[I].data!=0) s++;
     if(H[I].next!=NULL) {
       Q=H[I].next;t=2;
       while(Q!=NULL) {s+=t;t++;
        cout<<Q->data<<" "; 
        Q=Q->next; 
         }   
     }
     cout<<endl;
  }
}

void cari(larik H,int N)
{int lokasi,a,i,p,k=1;list q;bool ada;
  cout<<"\nmasukkan data yg dicari : ";cin>>a;
   p=prima(N);
   i=a % p;ada=false;
   if ((H[i].data==a) && (a!=0)) {ada=true;lokasi=i;}
   else
     if (H[i].next!=NULL) {
       q=H[i].next;ada=false;
       while (q!=NULL &&  !ada) {
        if (q->data==a) {ada=true;lokasi=i;k++;} else {q=q->next;k++;}
        }
        
     } else  ada=false;
   if (ada) cout<<"data ada di "<<lokasi<<" ke "<<k;
   else cout<<"data tidak ada";
}
    

int main()
{ int x[20001],n;larik H;
  BuatDataBeda(x,n);
  cout<<endl;
  getch();
  hashing(x,n,H);
  cout<<endl;getch();
  cout<<"rata-rata : "<<(float)s/n;
  cari(H,n);
  return 0;
}


