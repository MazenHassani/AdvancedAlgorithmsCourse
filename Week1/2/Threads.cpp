#include<iostream>
#include<algorithm>
using namespace std;

bool can (int a[], int n, int k, int M)
{
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+= a[i]/M;
    }
    return (sum>=k);
}

int BS_theAnswer (int a[], int n, int k)
{
    int L=0,R=1000001,M;
    while (R-L>1)
    {
        M=L+(R-L)/2;
        if (can(a,n,k,M))
            L=M;
        else
            R=M;
    }
    return L;
}
int main() {
    int n,k, a[1001];
    cin>>n>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout << BS_theAnswer(a,n,k)<<endl;
}