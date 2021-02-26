#include<iostream>
#include<algorithm>
#include <stack>
#include <string>
using namespace std;

stack <char> msg;

char opening (char r)
{
    if (r=='}')return '{';
    if (r==']')return '[';
    if (r==')')return '(';
}

int main() {
    string r;cin>>r;
    for (int i = 0; i < r.length(); i++)    
    {
        if (r[i]=='{' || r[i]=='[' || r[i]=='(')
            msg.push(r[i]);
        else{
            if (msg.top()==opening (r[i]))
                msg.pop();
            else{
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
    return 0;
}