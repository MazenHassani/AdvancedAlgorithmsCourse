#include<bits/stdc++.h>
using namespace std;

typedef long long li;
const int N = 3000007;
int n;
li bit[N];
li a [N];
int M;

li bit1[N], bit2[N];
 
void update(li *bit, int x, int v) {
    for (++x; x < N; x += x & -x)
        bit[x] += v;
}

void update(int l, int r, int v) {
    update(bit1, l, v);
    update(bit1, r + 1, -v);
    update(bit2, l, v * (l - 1));
    update(bit2, r + 1, -v * r);
}

li sum(li *bit, int x) {
    li res = 0;
    for (++x; x > 0; x -= x & -x)
        res += bit[x];
 
    return res;
}
 
li query(int x) {
    return sum(bit1, x) * x - sum(bit2, x);
}
 
li query(int l, int r) {
    return query(r) - query(l - 1);
}

int main ()
{
    ios_base::sync_with_stdio (false);
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        int t, l, r, d;
        cin>>t>>l>>r;
        if(t==1){
            //inc
            cin>>d;
            update(l, r, d);
        } else if (t==2){
            //sum
            cout<<query(l, r)<<endl;
        }
    }
    return 0;
}