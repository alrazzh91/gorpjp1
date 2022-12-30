#include<iostream>    
#include<algorithm>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
using namespace std;
typedef int larik [250000];
larik x;

void buatdata(int x[], int n) {
    srand(time(NULL));
	for (int i=0; i<n; i++) {
		x[i] = rand() % 100;
	}
}

void printarr (int x[], int n) {
	for (int i=0; i<n; i++) {
		cout<<x[i]<<" ";
	}
	cout<<endl;
}

int main() {  
    int n;
    cout<<"n: ";
    cin>>n;
      
    cout<<"Before sorting array : ";
    buatdata(x, n);
    for(int i=0; i<n; i++){
        cout<<" "<<x[i];
    }
     
    sort(x, x + n);//Sorting demo array
     
    cout<<"\n\nAfter sorting array : ";
    for(int i=0; i<n; i++){
        cout<<" "<<x[i];
    }
    return 0;
}
