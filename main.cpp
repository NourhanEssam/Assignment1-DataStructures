#include <iostream>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

string postfix2infix(string postfix);

int main()
{
    string postfix,infix;

    while(1)
    {
        cout<<"Please enter a postfix expression :"<<endl;
        getline(cin,postfix);

        infix = postfix2infix(postfix);
        cout<<"The infix expression is : "<<infix<<endl<<endl;
    }

    return 0;
}

string postfix2infix(string postfix)
{
    string result,infix;
    string operators[] = {"+","-","*","/","^"};
    stack<string> Stack;
    bool isSign;
    int numberOfOperands=0,i = 0;
    string postfixArray[1000];
    stringstream ssin(postfix);

    while (ssin.good() && i < postfix.size()){
        ssin >> postfixArray[i];
        ++i;
        numberOfOperands++;
    }

    for(i = 0; i < numberOfOperands; i++){
        cout << postfixArray[i] << endl;
    }

    for(int i=0;i<numberOfOperands;i++)
    {
        isSign=false;
        for(int j=0;j<5;j++)
        {
            //if sign
            if(postfixArray[i] == operators[j] && isSign == false)
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
            Stack.push(postfixArray[i]);
        }
    }
    infix = Stack.top();
    return infix;
}
