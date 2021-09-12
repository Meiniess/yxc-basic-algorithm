#include <iostream>
using namespace std;

//不知道为什么跑不通-0.001
double bsearch(double l, double r,double n)
{
    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= n)
            r = mid;
        else
            l = mid;
    }
    return l;
}

int main()
{
    double n, res;
    scanf("%lf", &n);
    if(n<0) 
    {
        res = bsearch(0, -n,-n);
        printf("%f", -res);
    }
    else{
        res = bsearch(0, n,n);
        printf("%f", res);
    }
    
}
