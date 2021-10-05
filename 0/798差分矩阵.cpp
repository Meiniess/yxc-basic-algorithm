#include <iostream>

using namespace std;
const int N = 1e3 + 10;
int a[N][N], s1[N][N], s2[N][N];
int n, m, q;

int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            s2[i][j] = s2[i - 1][j] + s2[i][j - 1] + a[i][j] - s2[i - 1][j - 1];
        }
    }
    while (q--)
    {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        //注意
        a[x1][y1] += c;
        a[x1][y2 + 1] -= c;
        a[x2 + 1][y1] -= c;
        a[x2 + 1][y2 + 1] += c;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            s1[i][j] = s1[i - 1][j] + s1[i][j - 1] + a[i][j] - s1[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << s1[i][j] - s2[i][j - 1] - s2[i - 1][j] + s2[i - 1][j - 1] << ' ';
        }
        cout << endl;
    }
    return 0;
}