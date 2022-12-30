#include <iostream>  
#include <conio.h>  
using namespace std;  
int main()  {  
    float* Ipk;  
    int i, n, countL = 0, countTL = 0;  
    cout << "banyak data : ";  
    cin >> n;  
    Ipk = new float[n];  
    for (i = 0; i < n; i++) {  
        Ipk[i] = (rand() % 100 + 1) / 25.0;  
        if (Ipk[i] > 2) {  
            cout << Ipk[i] << "  Lulus" << endl;  
            countL++;  
        }  
        else {  
            cout << Ipk[i] << "  Tidak lulus" << endl;  
            countTL++;  
        }  
    }  
    cout << "\nBanyak data yang Lulus =  " << countL;  
    cout << "\nBanyak data yang Tidak Lulus =  " << countTL;  
    getch();  
    return 0;  
}