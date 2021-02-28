#include<iostream>
#include<algorithm>
#include <stack>
#include <string>
using namespace std;

stack <int> s1,s2;

int main() {
    int n,x;
    char op;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>op;
        if (op=='+'){
            cin>>x;
            s1.push(x);
            cout<<1<<" + "<<x<<endl;
        }
        else if(op=='-'){
            if (s2.empty())
            {
                while(!s1.empty()){
                    cout<<1<<" - "<<s1.top()<<endl;
                    cout<<2<<" + "<<s1.top()<<endl;
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            cout<<2<<" - "<<s2.top()<<endl;
            s2.pop();
        }
    }   
    return 0;
}