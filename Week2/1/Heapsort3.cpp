#include<bits/stdc++.h>
using namespace std;

int Count=0;

void heapify (vector <int>& a, int i, int n)
{
    while (3 * i + 1 < n){
        int t=3 * i + 1;
        int j = t;
        if ( t + 1 < n && a[t + 1] > a[j])
            j = t + 1;
        if ( t + 2 < n && a[t + 2] > a[j])
            j = t + 2;
        if (a[i] < a[j]){
            Count++;
            swap (a[i], a[j]);
            i = j;
        } else break;
    }
}

int main ()
{
    int n;
    cin>>n;
    vector <int> a(n);
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    for (int i = n-1; i >= 0; i--){
         heapify(a,i,n);
    }

    while (n>1){
        n--;
        swap(a[0],a[n]);
        heapify(a, 0, n);
    }
    cout<<Count<<endl;
    for (int i = 0; i < a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}