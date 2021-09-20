#include <iostream>

using namespace std;

const int N = 10;
int n;
char q[N][N];
bool col[N], dg[N * 2], udg[N * 2];
void dfs(int x)
{
    if (x == n)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << q[i][j];
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (!col[i] && !dg[x+i] && !udg[n+i-x])
        {
            q[x][i] = 'Q';
            col[i] = dg[x + i] = udg[n + i-x] = true;
            dfs(x+1);
            col[i] = dg[x + i] = udg[n + i-x] = false;
            q[x][i] = '.';
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            q[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}