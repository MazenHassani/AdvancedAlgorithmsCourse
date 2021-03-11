#include<bits/stdc++.h>
using namespace std;

int n;
vector <int> a, h, r;

void heapify (int i){
    while (2 * i + 1 <n){
        int j = 2 * i + 1;
        if (j + 1 < n && a [h[j + 1]] > a[h[j]])
            j++;
        if (a[h[i]] < a[h[j]]){
            swap (h[i], h[j]);
            r[h[i]] = i;
            r[h[j]] = j;
            i = j;
        } else break;
    }
}

void up (int i){
    while (i > 0 && a[h[(i - 1) / 2]] < a[h[i]]){
        int j = (i - 1) / 2;
        swap (h[i], h[j]);
        r[h[i]] = i;
        r[h[j]] = j;
        i = j;
    }
}

int main (){
    cin>> n;
    a = h = r = vector <int> (n);
    for (int i = 0; i < n; i++){
        cin>>a[i];
        h[i]=r[i]=i;
    }
    for (int i = n-1; i >= 0; i--){
        heapify(i);
    }
    

    int m;
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        if (t==1){
           cout<< a[h[0]] << endl;
        }
        else{
            int j, x;
            cin >> j >> x;
            j--;
            a[j] = x;
            heapify(r[j]);
            up(r[j]);
        }
    }
    
    return 0;
}