#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int lower_bound (int a[], int n, int x)
{
    int M,R=n,L=-1;
    while(R-L>1)
    {
        M=L+(R-L)/2;
        if (a[M]>x) //f(M)
            R=M;
        else
            L=M;
    }
    return R;
}

int main() 
{ 
    int n,m,x,a[200001];
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for (int i = 0; i < m; i++)
    {
        cin>>x;
        cout<<lower_bound(a, n, x)<<" ";
    }
    cout<<endl;
    return 0;
}