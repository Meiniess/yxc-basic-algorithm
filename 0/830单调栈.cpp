
#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int q[N];
int n;
int idx;
//本题本质上是一个数学问题
//用一个栈存储比较过的数据
//如果栈顶大于等于当前要比较的数i，则可以直接丢掉（因为对于i+1来讲，i的优先级肯定大于i-1）
int main()
{

    cin >> n;
    while (n--)
    {

        int x;
        cin >> x;
        while (idx && q[idx] >= x)
        {
            idx--;
        }
        if (idx)
            cout << q[idx] << ' ';
        else
            cout << -1 << ' ';

        q[++idx] = x;
    }
    return 0;
}