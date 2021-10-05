#include <stdio.h>
#include <string.h>

int main()
{
    char s1[10001], s[10001];
    int N, a, i, j, len;
    scanf("%d", &N);
    while (N--)
    {
        j = 0;
        s1[0] = 0;
        scanf("%s", s);
        len = strlen(s);
        for (i = 0; i < len; i++)
        {
            a = s[i];
            if (a == s1[j] + 1 || a == s1[j] + 2)
            {
                //匹配到了就把栈顶弹出
                s1[j] = 0;
                //如果匹配到了并且栈弹出后还非空，就j--
                if (j != 0)
                    j--;
            }
            else
            {
                //如果没匹配到，且栈非空，j++
                if (s1[j] != 0)
                    j++;
                //进栈
                s1[j] = a;
            }
        }
        //如果栈空了就说明都匹配到了
        if (s1[0] == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
}