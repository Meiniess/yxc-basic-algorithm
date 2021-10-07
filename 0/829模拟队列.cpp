#include<iostream>

using namespace std;
const int N=1e5+10;
int q[N];
int m;
int head=-1,tail=-1;
void push(int x)
{
    q[++tail]=x;
}
void pop()
{
    head++;
}
bool empty()
{
    return tail==head;
}
int query()
{
    return q[head+1];
}

int main()
{
    int x;
    string op;
    cin>>m;
    while (m--)
    {
        cin>>op;
        if(op=="push")
        {
            cin>>x;
            push(x);
        }
        else if(op == "pop")
        {
            pop();

        }
        else if(op=="empty")
        {
            if(empty()==true) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<query()<<endl;
    }
    return 0;
    
}