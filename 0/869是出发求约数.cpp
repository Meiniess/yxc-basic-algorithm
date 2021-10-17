#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector<int> get_divisors(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            res.push_back(i);
            if (i != x / i)
                res.push_back(x / i);
        }
        
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    cin >> n;
    while (n--)
    {
        int x;
        vector<int> res;
        cin >> x;
        res = get_divisors(x);
        for (auto i : res)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}