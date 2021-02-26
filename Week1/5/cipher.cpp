#include<iostream>
#include<cstring>
using namespace std;

int main ()
{
	int x,p=0;
	cin>>x;
    string msg;
    cin>>msg;
    cout<<msg[0];
    for (int i=0;i<x;i++)
    {
    	p=p+(i+1);
        if (p<x) cout<<msg[p];
    }
    cout<<endl;
    return 0;
}