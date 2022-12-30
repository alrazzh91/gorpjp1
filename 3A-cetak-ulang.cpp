#include <bits/stdc++.h>
using namespace std;
int main () {
    int N, M, i, j;
    1<=N,M<= 10;
    0<=i,j<=9;
    int Array[10][10];
    
    cin>>N>>M;
    
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            cin>>Array[i][j];
        }
    cout<<endl;    
    }
    
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            cout<<Array[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
    
}

