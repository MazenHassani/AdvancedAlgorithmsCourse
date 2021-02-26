#include<iostream>
#include<algorithm>
using namespace std;

int binarySearch (int a[], int n, int x)
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
    if (L>=0 && a[L]==x)
        return L;
    else return -1;
}

int lower_bound (int a[], int n, int x)
{
    int M,R=n,L=-1;
    while(R-L>1)
    {
        M=L+(R-L)/2;
        if (a[M]<x) //f(M)
            L=M;
        else
            R=M;
    }
    return R;
}

int main() {
    int n,m,a[100001],x;
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>a[i];
    sort(a,a+n);
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        cin>>x;
        int k=lower_bound(a,n,x);
        int answer = 2000000001;
        if (k<n)
            answer=min (answer, abs(a[k]-x));
        if (k>0)
            answer=min (answer, abs(a[k-1]-x));
        cout<<answer<<endl;
    }
    return 0;
}