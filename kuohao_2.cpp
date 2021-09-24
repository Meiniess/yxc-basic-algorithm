#include<iostream>
using namespace std;
struct Stack
    {
        char str[100];
        int i;//入栈的编号
    };
int main()
{
    int N;
    char c;
    Stack stack;
    cin>>N;
    getchar();
    while(N)
    {
        stack.i=-1;
        while((c=getchar())!='\n')
        {
            if(c=='['||c=='(')
                stack.str[++stack.i]=c;
            else if((stack.str[stack.i]=='['&&c==']')||(stack.str[stack.i]=='('&&c==')'))
                stack.i--;
            else
                {
                    stack.i=0;
                    break;
                }
        }
        if(stack.i==-1)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
        N--;
    }
    return 0;
}