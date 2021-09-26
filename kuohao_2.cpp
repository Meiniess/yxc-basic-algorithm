#include <iostream>
using namespace std;
struct Stack
{
    char str[10010];
    int i; //入栈的编号
};
int main()
{
    int N;
    char c;
    Stack stack;
    cin >> N;
    getchar();
    while (N--)
    {
        string c;
        stack.i = -1;
        cin>>c;

        for(int j=0;j<c.size();j++)
        {
            if (c[j] == '[' || c[j] == '(')
                stack.str[++stack.i] = c[j];
            else if ((stack.str[stack.i] == '[' && c[j] == ']') || (stack.str[stack.i] == '(' && c[j] == ')'))
                stack.i--;
            else
            {
                stack.i = 0;
                break;
            }
        }
        if (stack.i == -1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        
    }
    return 0;
}