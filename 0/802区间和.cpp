#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int N = 3e5 + 10;
int n, m;

int a[N], s[N];
vector<pii> add, query;
vector<int> alls;
int find(int x)
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] < x)
            l = mid + 1;
        else
            r = mid;
    }
    return r + 1;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        alls.push_back(l);
        alls.push_back(r);
        //查询的范围
        query.push_back({l, r});
    }
    //去重
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    //将很大的数域转化成各个数大小的位次
    for (auto item : add)
    {
        //找到要加的位置x
        //因为已经去重过了，所以不用想选哪种二分法
        int x = find(item.first);
        //在a数组的对应x位置上加上要加的值
        a[x] += item.second;
    }
    //求前缀和
    for (int i = 1; i <= alls.size(); i++)
        s[i] = s[i - 1] + a[i];
    //找到查询区间的l和r
    for (auto item : query)
    {
        int l = find(item.first), r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}