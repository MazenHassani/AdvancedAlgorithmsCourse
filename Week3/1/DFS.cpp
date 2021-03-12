#include<bits/stdc++.h>
using namespace std;

const int N = 600;

void DFS (int g[][], int n, int a, int b)
{
    
}

int main (){
    int n, a,b;
    int g[N][N];
    cin>>n>>a>>b;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin>>g[i][j];
    DFS (g, n, a, b);
    return 0;
}