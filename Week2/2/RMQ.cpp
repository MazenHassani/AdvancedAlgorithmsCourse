#include<bits/stdc++.h>
using namespace std;

const int N = 200001;

int segtree[4 * N], a[N];

void buildRMQ (int id, int l, int r){
    if(l == r){
        segtree[id] = a[l];
        return;
    }
    int m = (l + r) / 2;
    
    buildRMQ(2 * id + 1, l, m);
    buildRMQ(2 * id + 2, m + 1, r);

    segtree[id] = min(segtree[2 * id + 1], segtree[2 * id + 2]);
}

void updateRMQ (int p, int v, int id, int l, int r){
    if(l == r){
        segtree[id] = v;
        return;
    }

    int m = l + (r - l) / 2;

    if(p <= m){
        updateRMQ(p, v, 2 * id + 1, l , m);
    }
    else {
        updateRMQ(p, v, 2 * id + 2, m + 1, r);
    }

    segtree[id] = min(segtree[2 * id + 1], segtree[2 * id + 2]);
}

int queryRMQ(int L, int R, int id, int l, int r){
    if(r < L || R < l){
        return 1e9;
    }

    if(L <= l && r  <= R){
        return segtree[id];
    }

    int m = l + (r - l) / 2;

    int c1 = queryRMQ(L, R, 2 * id + 1, l , m);
    int c2 = queryRMQ(L, R, 2 * id + 2, m + 1 , r);

    return min(c1, c2);
}

int main (){
    int n, id, x;
    cin>>n;
    int l, r;
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    buildRMQ(0, 0, n-1);
    int m;
    cin>>m;
    for (int i = 0; i < m; i++){
        int t;
        cin>>t;
        if (t==1){
            cin>>id>>x;
            id--;
            updateRMQ(id, x, 0, 0, n-1);
        } else if (t==2){
            cin>>l>>r;
            l--;
            r--;
            cout << queryRMQ(l, r, 0, 0, n-1) << endl;
        }
    }
    return 0;
}