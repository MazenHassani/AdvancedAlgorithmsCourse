#include<bits/stdc++.h>
using namespace std;

void heapify (vector<pair<int, int>>& h, int i, int n){
    while(2 * i + 1 < n){
        int j = 2 * i + 1;
        if (j + 1 < n && h[j + 1] < h[j])
            j++;
        if (h[i] > h[j]){
            swap (h[i], h[j]);
            i=j;
        } else 
            break;
    }
}

int main (){
    int n;
    cin>>n;
    vector<vector<int>>a (n);
    int m=0;
    for (int i = 0; i < n; i++){
        int k;
        cin>>k;
        a[i]= vector<int>(k);
        for (int j = 0; j < k; j++){
            cin>>a[i][j];
        }
        m += k;
    }
    vector<pair<int, int>> h;
    vector <int> p(n);
    for (int i = 0; i < n; i++){
        h.push_back(make_pair(a[i][ p[i]++ ], i));
    }
    for (int i = n-1; i >= 0; i--){
        heapify(h, i, n);
    }
    for (int i = 0; i < m; i++){
        cout<<h[0].first<<" ";
        int j=h[0].second;
        if (p[j] < a[j].size()){
            h[0].first= a[j][ p[j]++ ];
        }else {
            h[0].first = INT_MAX;
        }
        heapify(h, 0, n);
    }
    return 0;
}