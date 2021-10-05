#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 10;

int n;
vector<pii> segs, res;
void merge()
{
    sort(segs.begin(), segs.end());
    
    int st = -2e9, ed = -2e9;
    for (auto item : segs)
    {
        if (ed < item.first)
        {
            if (st != -2e9)
                res.push_back({st, ed});
            st = item.first, ed = item.second;
        }
        else ed=max(ed,item.second);

    }
    if(st!=-2e9) res.push_back({st,ed});
}
int main()
{
    cin >> n;
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }
    merge();
    cout<<res.size()<<endl;
    return 0;
}