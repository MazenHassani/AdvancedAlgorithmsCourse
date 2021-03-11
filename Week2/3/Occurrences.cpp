#include<bits/stdc++.h>
using namespace std;

typedef long long li;

const li N = 4e9 + 1000;

map <pair<li,li>, li> bit;
map<li, li> a;

li query(li x, li whichBit){
    li res = 0;
    for(; x > 0; x -= x & -x)
        res += bit[make_pair(whichBit,x)];
    return res;
}

li query(li l, li r, li whichBit){
    if(l == 1)
        return query(r, whichBit);
    return query(r, whichBit) - query(l - 1, whichBit);
}

void update(li x, li v, li whichBit){
    for(; x < N; x += x & -x)
        bit[make_pair(whichBit, x)] += v;
}

int main (){
    ios_base::sync_with_stdio (false);
    li n, k, x;
    scanf("%lld", &n);
    scanf("%lld", &k);
    for (li i = 1; i <= n; i++){
        scanf("%lld", &x);
        a[i+ 2e9] = x;
        update(i + 2e9, 1, x);
    }
    for (li i = 0; i < k; i++)
    {
        li t;
        scanf("%lld", &t);
        if (t==1){
            //add
            li pos, x;
            scanf("%lld", &pos);
            pos += 2e9;
            scanf("%lld", &x);
            update(pos, -1, a[pos]);
            a[pos]=x;
            update(pos, 1, x);
        } else if (t==2){
            li l, r, x;
            scanf("%lld", &l);
            scanf("%lld", &r);
            l += 2e9;
            r += 2e9;
            scanf("%lld", &x);
            li num = query(l, r, x);
            printf("%lld\n", num);
        }
    }
    return 0;
}