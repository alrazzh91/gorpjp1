#include <bits/stdc++.h>
using namespace std;
int main () {
    int x, y, n1, n2;
	
	cin>>n1;
	cin>>n2;
	
	for (int x=1; x<=n1; x++) {
		for (int y=1; y<=n2; y++) {
			cout<<" "<<x+y<<"\t";
		}
		cout<<endl;
	}
	return 0;
}

