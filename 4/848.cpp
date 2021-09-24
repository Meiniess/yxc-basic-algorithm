#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;

int d[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void topsort()
{
    queue<int> q;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (!d[i])
            q.push(i);

    while (q.size())
    {
        int t = q.front();
        ans.push_back(t);
        q.pop();
        
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (--d[j] == 0)
                q.push(j);
        }
    }
    
    if (ans.size() == n)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", ans[i]);
    }
    else
        puts("-1");
}

int main()
{
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        d[b]++;
    }
    topsort();

    return 0;
}
