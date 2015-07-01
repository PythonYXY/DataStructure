#include <iostream>
#include <stack>
#include <cstring>
#include <cstdio>

using namespace std;


int isp(char ch)
{
    switch(ch)
    {
    case '#' : return 0;
    case '(' : return 1;
    case '*' :
    case '/' : return 5;
    case '+' :
    case '-' : return 3;
    case ')' : return 6;

    }
}

int icp(char ch)
{
    switch(ch)
    {
    case '#' : return 0;
    case '(' : return 6;
    case '*' :
    case '/' : return 4;
    case '+' :
    case '-' : return 2;
    case ')' : return 1;

    }
}

int main()
{
    freopen("in_expression.txt", "r", stdin);
    // freopen("post_expression.txt", "w", stdout);
    stack <char> st;
    char ch = '#', ch1, op;
    st.push(ch);
    cin.get(ch);
    while(!st.empty()){

        if(isdigit(ch)){cout << ch; cin.get(ch);}
        else{
            ch1 = st.top();
            if(isp(ch1) < icp(ch)) {st.push(ch); cin.get(ch);}
            else if(isp(ch1) > icp(ch)) {op = st.top(); st.pop(); cout << op; }
            else{
                op = st.top();
                st.pop();
                if(op == '(') cin.get(ch);
            }
        }
    }
    cout << endl;
    return 0;
}
