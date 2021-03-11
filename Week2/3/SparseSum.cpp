#include<bits/stdc++.h>
using namespace std;

typedef long long li;

const li N = 1e18+1000;
map <li, li> bit;

li query(li x){
    li res = 0;
    for(; x > 0; x -= x & -x)
        res += bit[x];
    return res;
}

li query(li l, li r){
    if(l == 1)
        return query(r);
    return query(r) - query(l - 1);
}

void update(li x, li v){
    for(; x < N; x += x & -x)
        bit[x] += v;
}

int main (){
    ios_base::sync_with_stdio (false);
    li q, x;
    scanf("%lld", &q);
    for (li i = 0; i < q; i++)
    {
        li t;
        scanf("%lld", &t);
        if (t==1){
            //add
            li p, x;
            scanf("%lld", &p);
            scanf("%lld", &x);
            update(p, x);
        } else if (t==2){
            li l, r;
            scanf("%lld", &l);
            scanf("%lld", &r);
            li sum = query(l, r);
            printf("%lld\n", sum);
        }
    }
    return 0;
}