#include <iostream>

using namespace std;

int main()
{
    int a[100];
    int x = 1, b = 2;
    a[1] = 2;
    a[2] = 1;

    swap(a[x], a[b]);
    while(1);
    return 0;
}