#include<iostream>
#include<cstring>
using namespace std;

int main ()
{
    int len;
	string msg0,msg1;
    cin>>msg0>>msg1;
    if (msg0.length()<=msg1.length()) 
        len = msg0.length();
    else if (msg0.length()>msg1.length())
        len = msg1.length();
    
    int moves = msg0.length()+msg1.length();
    for (int i=0;i<len;i++)
    {
        if (msg0[msg0.length()-1 - i]!=msg1[msg1.length()-1 -i])
        {
            cout<<moves<<endl;
            return 0;
        }
        else
            moves-=2;
    }
    cout<<moves<<endl;
    return 0;
}