#include<iostream>
#include<algorithm>
using namespace std;

int main ()
{
    int n,a[100010];
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>a[i];
    sort(a,a+n);
    cout<<min(a[n-1]-a[1], a[n-2]-a[0])<<endl;
    return 0;
}