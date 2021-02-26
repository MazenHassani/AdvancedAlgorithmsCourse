#include<iostream>
#include<algorithm>
using namespace std;

int a [100000]={0};
int top=-1;
int bottom = 0;

void push(int x)
{
    top++;
    a[top]=x;
}
void pop()
{
    cout<<a[bottom]<<endl;
    bottom++;
}

int main() {
    int n, x;
    char id;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>id;
        if (id == '+')
        {
            cin>>x;
            push(x);
        }
        else pop();
    }
    return 0;
}