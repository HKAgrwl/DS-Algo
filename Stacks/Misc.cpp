#include <iostream>
using namespace std;
#include <math.h>
#include "UsingArray.cpp"

int prefixEvaluation(string s){
    StackUsingArray St;
    for (int i = s.length()-1; i>=0; i--)
    {
        if(s[i]>='0' && s[i]<='9'){
            St.push(s[i]-'0');
        }else{
            int op1 = St.top();
            St.pop();
            int op2 = St.top();
            St.pop();
            
            switch (s[i])
            {
                case '+':
                    St.push(op1+op2);
                    break;
                case '-':
                    St.push(op1-op2);
                    break;
                case '*':
                    St.push(op1*op2);
                    break;
                case '/':
                    St.push(op1/op2);
                    break;
                case '^':
                    St.push(pow(op1,op2));
                    break;
            }
        }
    }
    return St.top();
    
}

int main()
{
    cout<<prefixEvaluation("-+7*45+20");
    return 0;
}
