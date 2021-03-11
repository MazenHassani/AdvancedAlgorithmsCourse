#include<bits/stdc++.h>
using namespace std;

typedef long long li;

const int N = 1000006;
int n;
li bit[N];
int a [N];


li query(int x){
    x++;
    li res = 0;
    for(; x > 0; x -= x & -x)
        res += bit[x];
    return res;
}

li query(int l, int r){
    if(l == 0)
        return query(r);
    return query(r) - query(l - 1);
}

void update(int x, int v){
    x++;
    for(; x < N; x += x & -x)
        bit[x] += v;
}

int main (){
    int id, x, m;
    cin>>n>>m;
    int l, r;
    for (int i = 0; i < n; i++){
        cin>>a[i];
        update(i, a[i]);
    }
    for (int i = 0; i < m; i++){
        int t;
        cin>>t;
        if (t==1){
            cin>>id>>x;
            id--;
            update(id, x-query(id, id));
        } else if (t==0){
            cin>>l>>r;
            l--;
            r--;
            cout << query(l, r) << endl;
        }
    }
    return 0;
}