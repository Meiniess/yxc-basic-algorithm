#include <iostream>
using namespace std;

const int N = 10;

int n;
int path[N];//记录路径上所做出的选择
bool st[N];//记录哪些数字被用过

void dfs(int u)
{
    if(u == n)
    {
        for(int i=0; i<n; i++)  cout << path[i] << ' ';
        return;
    }

    for(int i=1; i<=n; i++)
    {
        if(!st[i])
        {
            path[u] = i;
            st[i] = true;
            dfs(u+1);
            path[u] = 0;
            st[i] = false;
        }
    }
}

int main()
{
    cin >> n;

    dfs(0);

    return 0;
}
