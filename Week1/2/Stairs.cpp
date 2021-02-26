#include<iostream>
#include<cstring>
using namespace std;

int main ()
{
    int n,x,t=0,stairs=1,steps[1000]={0};
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>x;
        if (x==1 && i!=0)
        {
            stairs++;
            steps[stairs]=1;
        }
        else steps[stairs]++;
    }
    cout<<stairs<<endl;
    for (int i=1;i<=stairs;i++)
    	cout<<steps[i]<<" ";
    cout<<endl;
    return 0;
}