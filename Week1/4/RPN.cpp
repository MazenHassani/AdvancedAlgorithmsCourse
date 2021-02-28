#include<iostream>
#include<algorithm>
#include <stack>
#include <string>
using namespace std;

stack <int> s;

void calc (char op)
{
    int a = s.top();
    s.pop();
    int b = s.top();
    s.pop();
    if (op=='+') s.push(b+a);
    else if (op=='-') s.push(b-a);
    else if (op=='*') s.push(b*a);
    else if (op=='/') s.push(b/a);
    else cout<<"ERROR";
    return;
}

int main() {
    char r;
    while (cin>>r)
    {
        if (r>='0' && r<='9')
            s.push(int(r-'0'));
        else calc(r);
    }
    cout<<s.top()<<endl;
    return 0;
}