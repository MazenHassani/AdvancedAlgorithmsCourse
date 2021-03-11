#include<bits/stdc++.h>
using namespace std;

typedef long long li;

const int N = 1000007;
int n;
li bit[N];
int a [N];

li query(int x){
    li res = 0;
    for(; x > 0; x -= x & -x)
        res += bit[x];
    return res;
}

li query(int l, int r){
    if(l == 1)
        return query(r);
    return query(r) - query(l - 1);
}

void update(int x, int v){
    for(; x < N; x += x & -x)
        bit[x] += v;
}

int main (){
    ios_base::sync_with_stdio (false);
    int n, q;
    cin>>n>>q;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
        update(i, a[i]);
        update(i+1, -1*a[i]);
    }
    for (int i = 0; i < q; i++){
        int t;
        cin>>t;
        if (t==1){
            int l, r, x;
            cin>>l>>r>>x;
            update(l, x);
            update(r + 1, -x);
        } else if (t==2){
            int id;
            cin>>id;
            cout << query(id) << endl;
        }
    }
    return 0;
}