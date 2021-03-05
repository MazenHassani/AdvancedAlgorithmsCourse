#include<iostream>
#include<algorithm>
#include <queue>
using namespace std;

bool solve(string s, string t)
{
    int i=0,j=0;
    while ( (i<s.length()) && (j<t.length()) ) {
        if (s[i]==t[j]);
        else if (s[i]=='+')
        {
            return false;
        }
        else 
        {
            i++;
            if ( (i>=s.length()) || (s[i]!='-') ) 
            {
                return false;
            }
        }
        i++;
        j++;
    }
    return (i == s.length()) && (j == t.length());
}

int main() {
    string s,t;
    int k;
    cin>>k;
    for (int i = 0; i < k; i++)
    {
        cin>>s>>t;
        if (solve(s,t))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}