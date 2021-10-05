#include<iostream>
using namespace std;
const int N=1e5+10;

int main()
{
    double l=-10000,r=10000;
    double n;
    cin>>n;
    double mid;
    while(r-l>1e-8)
    {
        mid=(l+r)/2;
        if(mid*mid*mid<n) l=mid;
        else r=mid;
    }
    //cout有些数据精度不够，要用print，"%lf",格式化数据
    printf("%lf",mid);
    return 0;
}