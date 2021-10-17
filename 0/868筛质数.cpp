#include<iostream>
#include<vector>
using namespace std;
int n;
const int N=1e6+10;
int q[N],st[N];
vector<int>res;

void shai()
{
    for (int i = 2; i <= n; i++)
    {
        if(st[i]==1) continue;
        res.push_back(i);
        for (int j = i*2; j <= n; j+=i)
        {
            st[j]=1;
        }
    }
}

int main()
{
    cin>>n;
    
    shai();
    cout<<res.size();
    
    return 0;
}