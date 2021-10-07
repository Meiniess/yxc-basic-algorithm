//拉链法
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1e5 + 3;
int n;
int e[N], ne[N], idx;
int q[N];
void insert(int x)
{
    int t = (x % N + N) % N;
    e[idx]=x;
    ne[idx]=q[t];
    q[t]=idx++;
}

bool find(int x)
{
    int t = (x % N + N) % N;
    for (int i = q[t]; i != -1; i=ne[i])
    {
        if(e[i]==x) return true;
    }
    return false;
}

int main()
{
    memset(q, -1, sizeof q);
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