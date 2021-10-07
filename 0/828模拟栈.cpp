#include<iostream>

using namespace std;
const int N=1e5+10;
int q[N];
int m;
int tail=-1;
void push(int x)
{
    q[++tail]=x;
}
void pop()
{
    tail--;
}
bool empty()
{
    return tail==-1;
}
int query()
{
    return q[tail];
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