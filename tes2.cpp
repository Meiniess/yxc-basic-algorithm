#include <bits/stdc++.h>
using namespace std;

int son[1000005][30], cnt = 1;
char str[70];
int main()
{
    memset(son, 0, sizeof(son));
    while (scanf("%s", str) != EOF)
    {
        int now = 1;
        for (int i = 0; i < strlen(str); i++)
        {
            if (!son[now][str[i] - 'A'])
            { //建立新节点
                son[now][str[i] - 'A'] = ++cnt;
                now = son[now][str[i] - 'A'];
            }
            else
                now = son[now][str[i] - 'A'];
        }
    }
    cout << cnt << endl;
    return 0;
}