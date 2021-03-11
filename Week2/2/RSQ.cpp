#include<bits/stdc++.h>
using namespace std;

typedef long long li;

const int N = 200001;

li segtree[4 * N], a[N];

void buildRSQ (int id, int l, int r){
    if(l == r){
        segtree[id] = a[l];
        return;
    }
    int m = (l + r) / 2;
    
    buildRSQ(2 * id + 1, l, m);
    buildRSQ(2 * id + 2, m + 1, r);

    segtree[id] = segtree[2 * id + 1] + segtree[2 * id + 2];
}

void updateRSQ(int i, int val, int id, int l, int r){
    if(l == r){
        segtree[id] = val;
        return;
    }

    int m = l + (r - l) / 2;

    if(i <= m){
        updateRSQ(i, val, 2 * id + 1, l , m);
    }
    else {
        updateRSQ(i, val, 2 * id + 2, m + 1, r);
    }
    segtree[id] = segtree[2 * id + 1] + segtree[2 * id + 2];
}

li queryRSQ(int L, int R, int id, int l, int r){
    if(r < L || R < l){
        return 0;
    }

    if(L <= l && r  <= R){
        return segtree[id];
    }

    li m = l + (r - l) / 2;

    li c1 = queryRSQ(L, R, 2 * id + 1, l , m);
    li c2 = queryRSQ(L, R, 2 * id + 2, m + 1 , r);

    return c1 + c2;
}

int main (){
    int n, id, x, m;
    cin>>n>>m;
    int l, r;
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    buildRSQ(0, 0, n-1);
    for (int i = 0; i < m; i++){
        int t;
        cin>>t;
        if (t==1){
            cin>>id>>x;
            id--;
            updateRSQ(id, x, 0, 0, n-1);
        } else if (t==0){
            cin>>l>>r;
            l--;
            r--;
            cout << queryRSQ(l, r, 0, 0, n-1) << endl;
        }
    }
    return 0;
}