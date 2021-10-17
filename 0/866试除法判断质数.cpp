#include <iostream>

using namespace std;

int n;
const int N = 110;

bool isprime(int x)
{
    //1不是质数
    if (x < 2)
        return false;
    bool flag = true;
    //遍历2~根号2
    for (int i = 2; i <= x / i; i++)
    {
        //如果能整出就不是质数
        if (x % i == 0)
            flag = false;
    }
    return flag;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if (isprime(x))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}