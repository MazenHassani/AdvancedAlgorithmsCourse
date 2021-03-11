#include<bits/stdc++.h>
using namespace std;

struct heap {
    heap* l;
    heap* r;
    int x;
    heap(int x): l(nullptr), r(nullptr), x(x){
    }
};

heap* merge (heap* a, heap* b){
    if (!a || !b)
        return !b ? a: b;
    if (a->x < b->x)
        swap (a, b);
    if (rand() % 2 == 0)
        a->l = merge (a->l, b);
    else
        a->r = merge (a->r, b);
    return a;
}

int main (){
    int m;
    cin>>m;
    vector <heap*> h;
    for (int i = 0; i < m; i++)
    {
        string t;
        cin >> t;
        if(t == "new"){
            h.push_back(nullptr);
        } else {
            int id;
            cin >> id;
            id--;
            if (t == "push"){
                int x;
                cin >> x;
                h[id]=merge(h[id], new heap(x));
            } else if (t== "pop"){
                cout<< h[id]->x <<endl;
                h[id]= merge (h[id]->l, h[id]->r);
            } else if (t=="merge"){
                int jd;
                cin>>jd;
                jd--;
                h.push_back(merge(h[id], h[jd]));
            }
        }
    }
    return 0;
}