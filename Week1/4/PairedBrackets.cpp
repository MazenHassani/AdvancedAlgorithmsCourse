#include<iostream>
#include<algorithm>
#include <stack>
#include <string>
using namespace std;

stack <pair<int, char>> s;

char matching (char r)
{
    if (r=='{')return '}';
    if (r=='[')return ']';
    if (r=='(')return ')';
    else return 'w';
}

int main() {
    int a[101]={0};
    string r;
    cin>>r;
    for (int i = 0; i < r.length(); i++)
    {
        if (r[i]=='{' || r[i]=='[' || r[i]=='(')
        {
            s.push({i, r[i]});
        }
        else
        {
            a[s.top().first]=i;
            a[i]=s.top().first;
            s.pop();
        }
    }
    for (int i = 0; i < r.length(); i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}