#include<iostream>
#include<algorithm>
using namespace std;

int main ()
{
    int n,a[100000];
    cin>>n;
    int min=-1,AlMin=-2,max=100000,Almax=100001;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        if (a[i]<Almin)
        {
            Almin=a[i];
            if (a[i]<min)
            {
                min=a[i];
            }
        }

    }

    return 0;
}