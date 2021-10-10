#include <iostream>
#include <cstring>
using namespace std;
#define N 510
#define M 100010

int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
int st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

bool find(int x)
{
    //遍历所有关联节点
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        //如果没被考虑过
        if (!st[j])
        {
            st[j] = 1;
            //如果没有心有所属，或者心有所属的人可以移情别恋
            if (!match[j] || find(match[j]))
            {
                //匹配到了
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}
//本质是一个配对的算法
//最大匹配讲的就是一个点只能选择某一个点，而不能多选，这种情况下图中有多少条满足条件的边
//遍历所有边给他找对象，st表示第i条边考虑过的人，match表示n2匹配的谁
//对当前节点遍历他所有看上的人，如果看上的人已经心有所属，看看能不能帮他另找一个
//如果心无所属，则res++,如果能再找一个res++
int main()
{
    cin >> n1 >> n2 >> m;
    memset(h, -1, sizeof h);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    
    int res = 0;
    for (int i = 1; i <= n1; i++)
    {
        memset(st, 0, sizeof st);
        if (find(i))
            res++;
    }

    cout << res;
    return 0;
}