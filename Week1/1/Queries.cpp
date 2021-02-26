#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main() 
{ 
    int n,m,x,a[100000];
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for (int i=0;i<m;i++)
    {
        cin>>x;
        int *t;
        t = lower_bound(a , a+n, x);
        int count = t-a;
        cout
    }
    cout<<endl;
    return 0;
}