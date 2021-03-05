#include<bits/stdc++.h>
using namespace std;

int Count=0;

void heapify (vector <int>& a, int i, int n)
{
    while (2*i+1 <n){
        int j=2*i+1;
        if (j+1<n&&a[j+1]>a[j])j++;
        if (a[i]<a[j]){
            Count++;
            swap (a[i],a[j]);
            i=j;
        } else break;
    }
}
void HeapPrint (int a[], int n)
{
    for (int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
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
    // for (int t = n; t >= 0; t--)
    // {
    //     int i=t-1;
    //     while (i>0 && a[(i-1)/2] < a[i]){
    //         swap (a, i, (i-1)/2);

    //         adjs[k].first=(i-1)/2;
    //         adjs[k].second=i;
    //         k++;

    //         i=(i-1)/2;
    //     }
    // }
    
    // cout<<k<<endl;
    // for (int i = 0; i < k; i++){
    //     cout<<adjs[i].first<<" "<<adjs[i].second<<endl;
    // }
    // HeapPrint(a,n);
    return 0;
}