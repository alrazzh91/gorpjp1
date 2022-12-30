#include <bits/stdc++.h>
using namespace std;
int main () {
    string B;
	int T;
    1600<=T<=2000;
	
	cin>>B>>T;
	
		if (B=="FEB") {
			if((T%4==0 && T%100!=0) || T%400==0) {
                cout<<"29";
            }
            else {
                cout<<"28";
            }
		}
        else if (B=="JAN" || B=="MAR" || B=="MAY" || B=="JUL" || B=="AUG" || B=="OCT" || B=="DEC") {
		    cout<<"31";
        }
        else if (B=="APR" || B=="JUN" || B=="SEP" || B=="NOV") {
        	cout<<"30";
        }
        
	return 0;
}
