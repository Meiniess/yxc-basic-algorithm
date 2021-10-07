#include <iostream>
#include <unordered_map>
#include <stack>
#include<cstring>
#include<algorithm>
using namespace std;
stack<int> num;
stack<char> op;
void eval()
{   
    //注意，一定先取b再取a，因为是倒着计算，所以第一个数是b而不是a
    auto b = num.top();
    num.pop();
    auto a = num.top();
    num.pop();
    auto c = op.top();
    op.pop();
    int x;
    if (c == '+')
        x = a + b;
    else if (c == '-')
        x = a - b;
    else if (c == '*')
        x = a * b;
    else
        x = a / b;
    num.push(x);
}

int main()
{
    unordered_map<char, int> map = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            int x = 0, j = i;
            while (j < s.size() && isdigit(s[j]))
            {
                x = x * 10 + s[j++] - '0';
            }
            i = j - 1;
            num.push(x);
            
        }
        else if (s[i] == '(')
            op.push(s[i]);
        else if (s[i] == ')')
        {
            while (op.top() != '(')
            {
                eval();
            }
            op.pop();
        }
        else
        {
            while (op.size() && op.top() != '(' && map[op.top()] >= map[s[i]])
            {
                eval();
            }
            op.push(s[i]);
        }
    }
    while (op.size())
    {
        eval();
    }
    cout << num.top() << endl;
    return 0;
}