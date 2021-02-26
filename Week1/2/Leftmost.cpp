#include<iostream>
using namespace std;

int binarySearch (int a[], int n, int x)
{
    int M,R=n,L=-1;
    while(R-L>1)
    {
        M=L+(R-L)/2;
        if (a[M]>=x) //f(M)
            R=M;
        else
            L=M;
    }
    if (R<n && a[R]==x)
        return R;
    else return -1;
}

int lower_bound (int a[], int n, int x)
{
    int M,R=n,L=-1;
    while(R-L>1)
    {
        M=L+(R-L)/2;
        if (a[M]>=x) //f(M)
            R=M;
        else
            L=M;
    }
    return R;
}

int bisect_right (int a[], int n, int x)
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

int main() {
    int n,m,a[200001],x;
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>a[i];
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        cin>>x;
        int pos = binarySearch(a,n,x);
        if (pos!=-1) cout<<pos+1<<" ";
        else cout<<-1<<" ";
    }
    cout<<endl;
    return 0;
}