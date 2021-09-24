#include <stdio.h>
#include <string.h>
int main()
{
    char s1[20001], s[20001];
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
            if (a == s1[j] + 1 | a == s1[j] + 2)
            {
                s1[j] = 0;
                if (j != 0)
                    j--;
            }
            else
            {
                if (s1[j] != 0)
                    j++;
                s1[j] = a;
            }
        }
        if (s1[0] == 0)
            printf("Yes\n");
        else
            printf("No\n");
    }
}