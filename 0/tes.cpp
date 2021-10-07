#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 200003;
int x,t ;
int cal(int x)
{
    return t = (x % N + N) % N;
}
int main()
{
    cout<<cal(1000)<<' '<<cal(-1000);
}