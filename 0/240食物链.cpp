#include <iostream>

using namespace std;
const int N = 5e4 + 10;

int n, k;
//x的点数组和距离数组
int q[N], d[N];

int find(int x)
{
    if (q[x] != x)
    {
        //先用t存储x的父节点的根节点
        int t = find(q[x]);
        //x的距离=x到父节点的距离+父节点到根节点的距离
        d[x] += d[q[x]];
        //x的父节点等于根节点（路径压缩)
        q[x] = t;
    }
    //返回根节点
    return q[x];
}

int main()
{
    cin >> n >> k;
    //所有节点的父节点都初始化为自己
    for (int i = 1; i <= n; i ++ ) q[i] = i;
    //res记录假话的数量
    int res = 0;
    while (k--)
    {
        int m, x, y;
        cin >> m >> x >> y;
        //如果x或y大于数组范围，则是假话
        if (x > n ||y > n)
            res++;
        else
        {
            //取出x，y的根节点
            int px = find(x), py = find(y);
            if (m == 1)
            {
                //如果是同一根节点但到根节点的距离不是3的倍数，则是假话
                if (px == py && (d[x] - d[y]) % 3)
                    res++;
                //若不是同一根节点，合并两个集合，更新两个根节点之间的距离
                else if (px != py)
                {
                    q[px] = py;
                    d[px] = d[y] - d[x];
                }
            }
            else
            {
                //如果是同一根节点但到根节点的距离不是3的倍数差1，则是假话
                if (px == py && (d[x] - d[y] - 1) % 3)
                    res++;
                //若不是同一根节点，合并两个集合，更新两个根节点之间的距离
                else if (px != py)
                {
                    q[px] = py;
                    d[px] = d[y] - d[x] + 1;
                }
            }
        }
    }
    cout << res;
    return 0;
}