#include<bits/stdc++.h>
using namespace std;

struct event {
    int x, t, i;
};

bool operator <(const event& a, const event& b){
    return make_pair(a.x, a.t) < make_pair(b.x, b.t);
}

int main (){
    int L, n ;
    cin >> L >> n;
    vector <event> e;
    vector <int> c (n);

    for (int i = 0; i < n; i++){
        int l, r;
        cin>> l >> r >> c[i];
        if (l < r){
            e.push_back({l, +1, i});
            e.push_back({r, -1, i});
        }
    }
    sort(e.begin(), e.end());

    set <int> active;
    int j=0;
    for (int i = 0; i < L; i++){
        while (j < e.size() && e[j].x==i){
            if (e[j].t==1)
                active.insert(e[j].i);
            else
                active.erase(e[j].i);
            j++;
        }
        if (active.empty()) cout<<0<<" ";
        else cout<< c[*active.rbegin()]<< " ";
    }
    cout<< endl;
    return 0;
}