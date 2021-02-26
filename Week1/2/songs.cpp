#include<iostream>
#include<algorithm>
using namespace std;

int main ()
{
    int n,m,s1,s2,comp[10000000]={0};
    long long int minSum=0,maxSum=0;
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>s1>>s2;
        comp[i]=s1-s2;
        minSum+=s2;
        maxSum+=s1;
    }
    if (maxSum<=m)
    {
        cout<<0<<endl;
        return 0;
    }
    if (minSum>m)
    {
        cout<<-1<<endl;
        return 0;
    }
    if (minSum==m)
    {
        cout<<n<<endl;
        return 0;
    }
    sort(comp, comp+n);
    long long int newSum = maxSum;
    for (int i=0;i<n;i++)
    {
        newSum = newSum - comp[n-1-i];
        if (newSum<m)
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}