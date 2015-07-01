#include <iostream>
#include <stack>
#include <cstdio>
#include <stdlib.h>

using namespace std;

stack<double> st;


void do_operate(char op)
{
    double left, right, value;

    if(st.empty()) {cout << "Stack empty!" << endl; exit(1);}
    right = st.top();
    st.pop();
    if(st.empty()) {cout << "Stack empty!" << endl; exit(1);}
    left = st.top();
    st.pop();

    switch(op)
    {
    case '+' : value = left + right; st.push(value); break;
    case '*' : value = left * right; st.push(value); break;
    case '-' : value = left - right; st.push(value); break;
    case '/' : value = left / right; st.push(value); break;
    }
}
int main()
{
    int i = 0;
    freopen("post_expression.txt", "r", stdin);
    char ch;
    double num;
    while(cin >> ch){
        switch(ch)
        {
        case '+' :
        case '-' :
        case '*' :
        case '/' : do_operate(ch); break;
        default :
            cin.putback(ch);
            cin >> ch;
            char * temp = new char[2];
            temp[0] = ch;
            temp[1] = '\0';
            num = atof(temp);
            st.push(num);
            delete []temp;
        }
    }

    cout << st.top() << endl;
    return 0;
}
