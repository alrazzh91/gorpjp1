#include <iostream>
#include <vector>
using namespace std;
int main () {
    int N;
    cin>>N;

    vector<vector<string>> keramik = {
        {"O",">","X","<"}, {"v","/","^","\\"}, {"X","<","O",">"}, {"^","\\","v","/"} };
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<keramik[i%4][j%4];
        }
        cout<<endl;
    }
    return 0;
}
