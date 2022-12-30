#include <iostream>
using namespace std;
//void toh(int ,char,char,char);
void toh(int x,char a ,char c,char b)
{
	if(x==1) {  
	  cout<<"Move the disc 1 from "<<a<<" to "<<c<<endl; //only disc remaining
	  x=x-1;
	}
	else{
		toh(x-1,a,b,c) ; //step 1
        cout<<"Move the disc "<<x<<" from "<<a<<" to "<<c<<endl;//step 2
		toh(x-1,b,c,a); // step 3
	}
}
int main()
{	char a,b,c;
	int x;
	a='A'; //Start disc
	b='B'; //Auxillary disc
	c='C'; //Destination Disc
	cout<<"Enter the number of discs :";
	cin>>x;
	toh(x,a,c,b);
	return 0;
}