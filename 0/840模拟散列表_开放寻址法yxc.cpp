//开放寻址法
//YXC
#include <cstring>
#include <iostream>
#include<unordered_map>

using namespace std;

const int N = 2e5 + 3,INF=0x3f3f3f3f;
int n;

int q[N];


int find(int x)
{
    int t = (x % N + N) % N;
    while (q[t]!=INF&&q[t]!=x)
    {
        t++;
        if(t == N) t=0;
    }
    return t;
}

int main()
{
    memset(q, 0x3f, sizeof q);
    cin >> n;
    while (n--)
    {
        int x;
        string op;
        cin >> op >> x;
        int t = find(x);
        if (op == "I") q[t]=x;
        else
        {
            if (q[t] == INF)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
    }
    return 0;
}