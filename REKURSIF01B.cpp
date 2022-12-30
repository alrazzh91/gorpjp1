#include<iostream>
#include<time.h>
using namespace std;
string s;
//int X[11]={65,79,72,76,85,75,76,73,75,77,71};
string S;

int X[11]={0,1,2,8,3,6,9,10,4,5,7};

void apa(int n){
  if(n<=10) {
     cout<<X[n]<<" ";    
     apa(2*n);
     apa(2*n+1);
	}
}   
int apaH(int n){
  if(n<1) return 1;
  else{
    return (2*apaH(n-1))%10;
	}
}  
void apa1(int n){
 cout<<"*";    
 if(n<=10) {
    apa(2*n+1);   
    S+=X[n];  
    apa(2*n+2);}
 else S+=" ";   
}     

double fak(int n)
{if (n<=1) return 1;else return fak(n-1)*n;
}

long long fibo(int n)
{ 
 if (n<=2) return 1; else return fibo(n-2)+fibo(n-1);
}

long long fibon(int n)
{long long a,b,c;
 if (n<=2) return 1;
  else {
   a=1;b=1;     
   for(int i=3;i<=n;i++) {
     c=a+b;
     a=b;b=c;       
   }  
   return c;
}    
}

int anu(int n)
{if (n<=2) return n;
 else return anu(n-1)+ 2 * n;
}

int fpb(int a, int b)
{ if (b==0) return a;else return fpb(b,a%b);
}


void itu(int n,string &s)
{string s1,s2;
  if (n<=1) s="yes ";
  else {itu(n-1,s1);
        itu(n-2,s2);
        s=s1+s2;
        }
}


void cobaR(int a,int b,int &c)
{int c1,c2,t;
  if (b-a<=1) c=a+b;
  else {
     t=(a+b)/2;  
     cobaR(a,t,c1);
     cobaR(t+1,b,c2);
     c=c1+c2;
   }
}

int main()
{int a,b,n,c;
 cout<<"MASUKKAN NILAI N : ";cin>>n;
// cobaR(1,n,c);
 //cout<<"c = "<<c;
 //cout<<fibo(n);
 //cin>>b;
 //cout<<fpb(n,b);
 // cout<<"anu "<<n<<" = "<<anu(n);
  clock_t begin_time = clock();
  cout<<"fIBONACI SUKU KE "<<n<<" = "<<fibo(n)<<endl;
  cout <<"Waktu proses = "<< float( clock () - begin_time )/CLOCKS_PER_SEC<<endl;

  // cout<<"faktorial "<<n<<" = "<<fak(n);
  //itu(n,s);
  //cout<<"hasil : "<<s;
   //cout<<apaH(n);  S += 77;   cout<<S;
   return 0;
}
