#include<bits/stdc++.h>
using namespace std;

int main (){
    int n, s, t;
    cin>>n>>s>>t;
    s--; t--;
    vector<vector<int>>g (n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            int e;
            cin>>e;
            if (e == 1)
                g[i].push_back(j);
        }
    vector<int>p(n, -1);
    p[s] = s;
    queue <int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int v: g[u])
            if (p[v] == -1){
                p[v] = u;
                q.push(v);
            }
    }
    if(p[t]== -1)
        cout << -1 << endl;
    else{
        vector <int> path;
        while (p[t] != t)
        {
            path.push_back(t);
            t = p[t];
        }
        path.push_back(t);
        reverse(path.begin(), path.end());
        cout<<path.size()-1<<endl;
        for (int u: path){
            cout<< u+1 << " ";
        }
        cout<<endl;
    }
    return 0;
} 