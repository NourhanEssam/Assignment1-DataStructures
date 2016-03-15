#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

string postfix2infix(string postfix);

int main()
{
    string postfix,infix;
    char c;
    while(1)
    {
        cout<<"Please enter a postfix expression :"<<endl;
        cin>>postfix;

        infix = postfix2infix(postfix);
        cout<<"The infix expression is : "<<infix<<endl;

        cout<<"To enter another expression press any key .. To exit press q .. "<<endl;
        cin>>c;
        if(c=='q')
            break;
    }

    return 0;
}

string postfix2infix(string postfix)
{
    string result,infix;
    string operators[] = {"+","-","*","/","^"};
    stack<string> Stack;
    bool isSign;

    for(int i=0;i<postfix.size();i++)
    {
        isSign=false;
        for(int j=0;j<5;j++)
        {
            //if sign
            if(postfix[i] == operators[j][0] && isSign == false)
            {
                isSign=true;
                string second = Stack.top();
                Stack.pop();
                string first = Stack.top();
                Stack.pop();

                result.append("(");
                result.append(first);
                result.append(operators[j]);
                result.append(second);
                result.append(")");
                Stack.push(result);
                result="";
            }
        }
        //if character
        if(isSign == false)
        {
            Stack.push(string (1,postfix[i]));
        }
    }
    infix = Stack.top();
    return infix;
}
