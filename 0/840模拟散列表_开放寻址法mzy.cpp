//开放寻址法
//自己写的
#include <cstring>
#include <iostream>

using namespace std;

const int N = 2e5 + 3,INF=0x3f3f3f3f;
int n;

int q[N];
void insert(int x)
{
    int t = (x % N + N) % N;
    while (q[t]==INF&&t<=N)
    {
        t++;
    }
    q[t] = x;
    
}

bool find(int x)
{
    int t = (x % N + N) % N;
    if(q[t]==INF) return false;
    while (q[t]!=INF)
    {
        if(q[t]==x) return true;
        t++;
    }
    return false;
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
        if (op == "I")
            insert(x);
        else
        {
            if (find(x) == true)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}