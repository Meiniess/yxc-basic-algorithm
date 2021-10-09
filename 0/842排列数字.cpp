#include<iostream>

using namespace std;

const int N=10;
int n,idx;
int q[N];
bool st[N];
//递归的深度搜索0到n-1的所有位置
void dfs(int x)
{
    if(x==n) 
    {
        //如果深度搜索到第n个，则直接打印输出
        for(int i=0;i<n;i++)  printf("%d ",q[i]);
        cout<<endl;
        return;

    }
    //从1到n遍历
    for(int i=1;i<=n;i++)
    {
        //如果i的标志位未置1，说明没用过
        if(!st[i])
        {
            //就在当前排列中加入i
            q[x]=i;
            //更新标志位
            st[i]=true;
            //从x+1开始搜索剩下所有的位置
            dfs(x+1);
            //更新标志为
            st[i]=false;
            //排列清零
            q[x]=0;

        }
    }

}

int main()
{
    cin>>n;
    //从0开始搜
    dfs(0);
    return 0;
}