#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int m;
int e[N], ne[N], la[N],idx;

void remove(int k)
{
    la[ne[k]] = la[k];
    ne[la[k]] = ne[k];
}

//k节点的右边加入一个点
void insert(int k, int x)
{
    e[++idx]=x;
    ne[idx]=ne[k],la[idx]=k;
    la[ne[k]]=idx,ne[k]=idx;
}


int main()
{

    cin >> m;
    ne[0]=1,la[1]=0;
    idx=1;
    while (m--)
    {
        int k, x;
        string op;
        cin >> op;
        if (op== "L")
        {

            cin >> x;
            insert(0,x);
        }
        else if (op == "R")
        {

            cin >> x;
            insert(la[1],x);
        }
        else if (op == "D")
        {

            cin >> k;
            remove(k+1);
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            insert(la[k+1], x);
        }
        else
        {
            cin >> k >> x;
            insert(k+1, x);
        }
    }
    
    for (int i =ne[0]; i != 1; i = ne[i])
    {
        cout << e[i] << ' ';
    }
    return 0;
}