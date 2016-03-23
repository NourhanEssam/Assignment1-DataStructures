#include <iostream>
#include <stack>
#include <sstream>
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
    bool special=false;

    while (ssin.good() && i < postfix.size()){
        ssin >> postfixArray[i];
        ++i;
        numberOfOperands++;
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
            special = false;
            for(int k=0;k<postfixArray[i].length();k++)
            {
                if(postfixArray[i][k]=='.')
                {
                    for(int l=0;l<k;l++)
                        result.append(string(1,postfixArray[i][l]));
                    result.append(".");
                    for(int l=k+1;l<postfixArray[i].length();l++)
                        result.append(string (1,postfixArray[i][l]));
                    Stack.push(result);
                    result="";
                    special=true;
                }
                else if(postfixArray[i][k]=='s' && postfixArray[i][k+1]=='i' && postfixArray[i][k+2]=='n')
                {
                    result.append("sin(");
                    for(int l=k+3;l<postfixArray[i].length();l++)
                    result.append(string(1,postfixArray[i][l]));
                    result.append(")");
                    Stack.push(result);
                    result="";
                    special=true;
                }
                else if(postfixArray[i][k]=='c' && postfixArray[i][k+1]=='o' && postfixArray[i][k+2]=='s')
                {
                    result.append("cos(");
                    for(int l=k+3;l<postfixArray[i].length();l++)
                    result.append(string(1,postfixArray[i][l]));
                    result.append(")");
                    Stack.push(result);
                    result="";
                    special=true;
                }
                else if(postfixArray[i][k]=='s' && postfixArray[i][k+1]=='q' && postfixArray[i][k+2]=='r' && postfixArray[i][k+3]=='t')
                {
                    result.append("sqrt(");
                    for(int l=k+4;l<postfixArray[i].length();l++)
                    result.append(string(1,postfixArray[i][l]));
                    result.append(")");
                    Stack.push(result);
                    result="";
                    special=true;
                }
                else
                {
                    if(k==postfixArray[i].length()-1 && !special)
                    Stack.push(postfixArray[i]);
                }
            }
        }
    }
    infix = Stack.top();
    return infix;
}
