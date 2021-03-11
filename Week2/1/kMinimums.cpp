#include<bits/stdc++.h>
using namespace std;

typedef long long li;

li a, b, A, B, C, M;

li nxt (){
    li result = a;
    li c = (a * A + b * B + C) % M;
    a = b;
    b = c;
    return result;
}

void heapify (vector <li>& h, int i, int n){
    while (2 * i + 1 <n){
        int j=2 * i + 1;
        if (j + 1 < n && h[j + 1] > h[j])
            j++;
        if (h[i] < h[j]){
            swap (h[i], h[j]);
            i=j;
        } else break;
    }
}

int main (){
    cin >> a >> b >> A >> B >> C >> M;
    int l, r, k;
    cin >> l >> r >> k;
    for (int i = 0; i < l; i++)
        nxt();
    
    vector <li> h;
    for (int i = 0; i < k; i++)
        h.push_back(nxt());

    for (int i = k -1; i >= 0; i--)
        heapify(h, i, k);

    for (int i = 0; i < r - l + 1 - k; i++){
        li x = nxt();
        if (h[0] > x){
            h[0]=x;
            heapify(h, 0, k);
        }
    }
    sort(h.begin(),h.end());
    for (int i = 0; i < k; i++)
    {
        cout<< h[i]<< " ";
    }
    cout<<endl;

    return 0;
}