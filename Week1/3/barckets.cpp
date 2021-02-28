#include<iostream>
#include<algorithm>
#include <stack>
#include <string>
using namespace std;

stack <char> msg;

char closing (char r)
{
    if (r=='{')return '}';
    if (r=='[')return ']';
    if (r=='(')return ')';
    else return 'w';
}

int main() {
    string r;
    cin>>r;
    for (int i = 0; i < r.length(); i++)    
    {
        if (r[i]=='{' || r[i]=='[' || r[i]=='(')
            msg.push(r[i]);
        else{
            if (!msg.empty())
            {
                if (r[i] == closing (msg.top()))
                {
                    msg.pop();
                }
            }
            else{
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    if (msg.empty())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}