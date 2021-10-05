#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int a[N], b[N];

int lowbit(int x)
{
    return x & (-x);
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        int res = 0;
        while (a[i])
        {
            a[i] -= lowbit(a[i]), res++;
        }
        b[i] = res;
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << ' ';
    }
    return 0;
}
