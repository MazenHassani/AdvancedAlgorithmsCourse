#include<iostream>
#include<algorithm>
using namespace std;

int a [100000]={0};
int top=-1;

void push(int x)
{
    top++;
    a[top]=x;
}
void pop()
{
    cout<<a[top]<<endl;
    top--;
}

int main() {
    int n, id, x;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>id;
        if (id == 1)
        {
            cin>>x;
            push(x);
        }
        else pop();
    }
    return 0;
}