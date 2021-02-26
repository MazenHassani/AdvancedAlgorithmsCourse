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
        if (a[M]>=x) //f(M)
            R=M;
        else
            L=M;
    }
    return L;
}

bool can (int M, int a, int b, int n)
{
    unsigned long long int c=0;
    c = (M/a)*(M/b);
    return (c>=n);
}

int BS_theAnswer (int n, int a, int b)
{
    int L=0,R=1000000000,M;
    while (R-L>1)
    {
        M=L+(R-L)/2;
        if (can(M, a, b, n))
            R=M;
        else
            L=M;
    }
    return R;
}
int main() {
    int t,a,b,n;
    cin>>t;
    for (int i = 0; i < t; i++)
    {
        cin>>n>>a>>b;
        cout << BS_theAnswer(n,a,b)<<endl;
    }
}