#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;
int n, m, x;
int A[N], B[N];

int main()
{
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
        cin >> B[i];

    for (int i = 0, j = m - 1; i < n; i++)
    {
        while (A[i] + B[j] > x)
            j--;
        if (A[i] + B[j] == x)
            printf("%d %d", i, j);
    }
    return 0;
}