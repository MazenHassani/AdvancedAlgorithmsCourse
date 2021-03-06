#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1000;
typedef long long li;

li segtreeRMQ[8 * N];
//li segtreeRSQ[8 * N];
li lazy[8 * N];

int a[N];

void push (int id, int l, int r){
    if (lazy[id] != -1){    
    //segtreeRSQ[id] = (r - l + 1) * lazy[id];
    segtreeRMQ [id] = lazy[id];

    lazy[2 * id + 1] = lazy[id];
    lazy[2 * id  +2] = lazy[id];

    lazy[id] = -1;
    }
}

//RMQ (Minimum)
void buildRMQ (int id, int l, int r){
    lazy[id]=-1;
    if(l == r){
        segtreeRMQ[id]= a[l];
        return;
    }
    int m = (l + r) / 2;
    
    buildRMQ(2 * id + 1, l, m);
    buildRMQ(2 * id + 2, m + 1, r);

    segtreeRMQ[id] = min(segtreeRMQ[2 * id + 1], segtreeRMQ[2 * id + 2]);
}

li queryRMQ(int L, int R, int id, int l, int r){
    push(id, l, r);
    if(r < L || R < l){
        return 1e9;
    }

    if(L <= l && r  <= R){
        return segtreeRMQ[id];
    }

    int m = l + (r - l) / 2;

    li c1 = queryRMQ(L, R, 2 * id + 1, l , m);
    li c2 = queryRMQ(L, R, 2 * id + 2, m + 1 , r);

    return min(c1, c2);
}



void update(int L, int R, int val, int id, int l, int r){
    push(id, l, r);
    if(r < L || R < l){
        return;
    }

    if(L <= l && r  <= R){
        lazy[id] = val;
        push(id, l, r);
        return;
    }

    int m = l + (r - l) / 2;

    update(L, R, val, 2 * id + 1, l , m);
    update(L, R, val, 2 * id + 2, m + 1 , r);
    
    // segtreeRSQ[id] = segtreeRSQ[2 * id + 1] + segtreeRSQ[2 * id + 2];
    segtreeRMQ[id] = min(segtreeRMQ[2 * id + 1], segtreeRMQ[2 * id + 2]);
}


int main (){
    int n, m;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    buildRMQ(0, 0, n-1);
    // buildRSQ(0, 0, n-1);
    cin>>m;
    for (int i = 0; i < m; i++){
        int t;
        cin>>t;
        int l, r, x;
        cin>>l>>r;
        l--;
        r--;
        if (t==1){
            cout<< queryRMQ(l, r, 0, 0, n-1) <<endl;
        } else if (t==2){
            cin>>x;
            update(l, r, x, 0, 0, n-1);
        }
    }
    return 0;
}