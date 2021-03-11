#include<bits/stdc++.h>
using namespace std;

const int N = 100001;
typedef long long li;

pair <int,int> segtreeRMQ[4 * N];
int a[N];
int visited[N]={0};
li segtreeRSQ[4 * N];


void buildRSQ (int id, int l, int r){
    if(l == r){
        segtreeRSQ[id] = visited[l];
        return;
    }
    int m = (l + r) / 2;
    
    buildRSQ(2 * id + 1, l, m);
    buildRSQ(2 * id + 2, m + 1, r);

    segtreeRSQ[id] = segtreeRSQ[2 * id + 1] + segtreeRSQ[2 * id + 2];
}

void updateRSQ(int i, int val, int id, int l, int r){
    if(l == r){
        segtreeRSQ[id] = val;
        return;
    }

    int m = l + (r - l) / 2;

    if(i <= m){
        updateRSQ(i, val, 2 * id + 1, l , m);
    }
    else {
        updateRSQ(i, val, 2 * id + 2, m + 1, r);
    }
    segtreeRSQ[id] = segtreeRSQ[2 * id + 1] + segtreeRSQ[2 * id + 2];
}

li queryRSQ(int L, int R, int id, int l, int r){
    if(r < L || R < l){
        return 0;
    }

    if(L <= l && r  <= R){
        return segtreeRSQ[id];
    }

    li m = l + (r - l) / 2;

    li c1 = queryRSQ(L, R, 2 * id + 1, l , m);
    li c2 = queryRSQ(L, R, 2 * id + 2, m + 1 , r);

    return c1 + c2;
}

void buildRMQ (int id, int l, int r){
    if(l == r){
        segtreeRMQ[id].first = a[l];
        segtreeRMQ[id].second = l;
        return;
    }
    int m = (l + r) / 2;
    
    buildRMQ(2 * id + 1, l, m);
    buildRMQ(2 * id + 2, m + 1, r);

    segtreeRMQ[id] = min(segtreeRMQ[2 * id + 1], segtreeRMQ[2 * id + 2]);
}

void updateRMQ (int i, int v, int id, int l, int r){
    if(l == r){
        segtreeRMQ[id].first = v;
        segtreeRMQ[id].second = l;
        return;
    }

    int m = l + (r - l) / 2;

    if(i <= m){
        updateRMQ(i, v, 2 * id + 1, l , m);
    }
    else {
        updateRMQ(i, v, 2 * id + 2, m + 1, r);
    }

    segtreeRMQ[id] = min(segtreeRMQ[2 * id + 1], segtreeRMQ[2 * id + 2]);
}

pair<int,int> queryRMQ(int L, int R, int id, int l, int r){
    if(r < L || R < l){
        return {1e9,-1};
    }

    if(L <= l && r  <= R){
        return segtreeRMQ[id];
    }

    int m = l + (r - l) / 2;

    pair<int,int> c1 = queryRMQ(L, R, 2 * id + 1, l , m);
    pair<int,int> c2 = queryRMQ(L, R, 2 * id + 2, m + 1 , r);

    return min(c1, c2);
}

int main (){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    buildRMQ(0, 0, n - 1);
    buildRSQ(0, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        int minValIndex = queryRMQ(0, n - 1, 0, 0, n - 1).second;
        updateRMQ(minValIndex, 1e9, 0, 0, n - 1);
        updateRSQ(minValIndex, 1, 0, 0, n - 1);
        minValIndex -= queryRSQ(0, minValIndex - 1, 0, 0, n - 1);
        cout << ++minValIndex << " ";
    }
    return 0;
}