#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int k=0;
pair<int, int> adjs[300010];
vector <int> heap;

void heapAdd (int x)
{
    heap.push_back(x);
    int i = heap.size() -1;
    while (i>0 && heap[(i-1)/2] < heap[i]){
        //swap (i, (i-1)/2);
        i=(i-1)/2;

        adjs[k].first=(i-1)/2;
        adjs[k].second=i;
        k++;
    }
}

void heapify(vector<int> vect, int i)
{
    int j;
    while (2i+1<heap.size())
    {
        j=2i+1;
        if (j+1<heap.size() && h[j+1]>h[j])
            j++;
        if (h[i]<h[j])
        {
            swap(i, j)
            i=j;
        }
        else
            break;
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