#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n, m, x;
int a[N], b[N];

int main()
{
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int i = 0, j = m - 1;
    for (int i = 0; i < n; i++)
    {
        while (a[i] + b[j] > x)
        {
            j--;
        }
        if(a[i]+b[j]==x) 
        {
            cout<<i<<' '<<j;
            break;
        }
    }
    return 0;
}