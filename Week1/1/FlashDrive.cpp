#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    bool visited [110]={false};
    int n, m, a[110],max=0;
    cin>>n>>m;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n, greater<int>());
    int t=0;
    for (int i=0; i<n;i++)
    {
    	//cout<<m<<endl;
        m-=a[i];
        t++;
        if (m<=0) break;
    }
    cout<<t<<endl;
    return 0;
}