#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main() 
{ 
    int n,m,x,sum=0,g[15]={0};
    cin>>n>>m;
    for (int i=0;i<n;i++)
    {
        cin>>x;
        g[x]+=1;
    }
    //for (int i=0;i<=m;i++){cout<<g[i]<<" ";}
    
    for(int i=1;i<m;i++)
        for(int j=i+1;j<=m;j++)
        {
            sum+=(g[i]*g[j]);
        }
    cout<<sum<<endl;
    return 0;
} 