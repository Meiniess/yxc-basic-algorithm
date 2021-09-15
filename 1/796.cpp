#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N=1e3+10;
int n ,m,q;
int a[N][N],s[N][N];
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for(int j=1;j<=m;j++)
        for(int i=1;i<=m;i++) scanf("%d",&a[j][i]);
    for(int j=1;j<=m;j++)
        for(int i=1;i<=m;i++) s[j][i]=s[j-1][i]+s[j][i-1]+a[j][i]-s[j-1][i-1];
    while(q--)
    {
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d",s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]);
    }
    return 0;
    
    

}