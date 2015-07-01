#include <iostream>
#include <deque>
#include <cstring>
using namespace std;


bool reverse_judge(const char * s)
{
    int half_len = strlen(s) / 2;
    deque<char> dq;
    int i = 0;
    while(s[i] != '\0') {dq.push_back(s[i]); i++;}
    int j = 0;
    for(; j < half_len; j++){
        if(dq.front() != dq.back()) break;
        dq.pop_front();
        dq.pop_back();
    }

    if(j < half_len) return false;
    else return true;

}

int main()
{
    const char * test1 = "xyzzyx";
    const char * test2 = "xyx";
    const char * test3 = "xyzyzx";

    if(reverse_judge(test1)) cout << "Yes"<< endl;
    else cout << "No" << endl;

    if(reverse_judge(test2)) cout << "Yes"<< endl;
    else cout << "No" << endl;

    if(reverse_judge(test3)) cout << "Yes"<< endl;
    else cout << "No" << endl;

    return 0;
}
