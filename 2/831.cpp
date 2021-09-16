#include <iostream>

using namespace std;

const int N = 100010, M = 1000010;

int n, m;
int ne[N];
char s[M], p[N];

int main()
{
    //s和p数组，从1开始数
    cin >> n >> p + 1 >> m >> s + 1;
    //求next指针：
    //实质跟kmp算法相同，只不过用自身匹配自身
    //遍历p数组，如果没匹配到且前面有匹配到的，就while找next指针匹配。
    //如果匹配到了，j就上位，且把j赋给当前i的next指针
    for (int i = 2, j = 0; i <= n; i ++ )
    {
        //如果j>0，即已经保存过j，且i和j不匹配，就往前跳，跳到next[j]重新匹配
        while (j && p[i] != p[j + 1]) j = ne[j];
        //只有两个字符匹配到时，j才会往前走，这样就保证了匹配不到时，去找next指针，next指针记录的就是上一个j
        if (p[i] == p[j + 1]) j ++ ;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= m; i ++ )
    {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++ ;
        if (j == n)
        {
            printf("%d ", i - n);
            j = ne[j];
        }
    }

    return 0;
}