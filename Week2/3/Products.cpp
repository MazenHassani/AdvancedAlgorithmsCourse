#include<bits/stdc++.h>
using namespace std;
 
typedef long long li;
 
const int N = 3000007;
int n;
li bit[N];
li a [N];
int M;

li query(int l, int r){
    li res = 1;
    for(; r >= l;){
        if ((r - (r & -r) ) >=l){
            res *= bit[r];
            res%=(M);
            r -= r & -r;
        } else {
            res *= a[r];
            res%=(M);
            r--;
        }
    }
    return res;
}
 
void update(int x, li v){
    for(; x < N; x += x & -x){
        bit[x] *= v;
        bit[x] %= M;
    }
}
 
int main (){
    ios_base::sync_with_stdio (false);
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    scanf("%d", &M);
    for (int i = 0; i < N; i++){
        bit[i]=a[i]=1;
    }
    
    for (int i = 1; i <= m; i++){
        int t, x, y;
        scanf("%d", &t);
        scanf("%d", &x);
        scanf("%d", &y);
        if (t==1){
            a[x] *= y;
            a[x] %= M;
            update(x, y);
        } else if (t==2){
            cout<< query(x, y)<< endl;
        }
    }
    return 0;
}