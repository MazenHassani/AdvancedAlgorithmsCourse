#include<bits/stdc++.h>
using namespace std;
 
typedef long long li;
 
const int N = 1000007;
int n;
li bit[N];
int a [N] = {0};
 
 
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
    int n, x;
    li sum=0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        x++;
        update(x, 1);
        sum+=query(x + 1, N);
    }
    printf("%lld\n", sum);
    return 0;
}