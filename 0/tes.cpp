#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 200003;
int x,t ;
int cal(int a,int b)
{
    return (a%b+b)%b;
}
int main()
{
    cout<<cal(10,3)<<endl;
    cout<<cal(-10,3)<<endl;
    cout<<cal(10,-3)<<endl;
    cout<<cal(-10,-3)<<endl;
}