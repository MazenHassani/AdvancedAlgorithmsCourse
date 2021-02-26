#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cyclic (int i, int p, int n)
{
    int newI=i;
    newI-=p;
    while (newI<0)
        newI+=n;
    //cout<<i<<" "<<newI<<endl;
    return newI;
}

//vector <int> a;
int shifted[200000]={0};
int main()
{
    int n, p, q,x;
    cin>>n>>p>>q;
    int index =0;
    for (index=0; index<n; index++)
    {
        cin>>x;
        int newIndex;
        //computeIndex
        newIndex = cyclic(index, q, n);
        if (newIndex<(n/2))
        {
            newIndex = cyclic(newIndex, p, n/2);
            //cout<<newIndex<<endl;
        }
        else
        {
            newIndex = cyclic(newIndex-(n/2), p, n/2);
            newIndex+=(n/2);
        }
        shifted[newIndex]=x;
        //cout<<x<<endl;
    }
    for (int i=0;i<n;i++)
        cout<<shifted[i]<<" ";
    cout<<endl;
    return 0;
}