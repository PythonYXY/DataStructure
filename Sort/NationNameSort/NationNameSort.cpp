#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(string n1, string n2)
{
    int i = 0;
    int len1 = n1.size();
    int len2 = n2.size();
    while(i != len1 && i!= len2 && n1[i] == n2[i]) i++;
    if(i != len1 && i != len2){return n1[i] < n2[i] ? true : false;}
    if(i == len1 && i != len2) return false;
    if(i != len1 && i == len2) return true;
    return true;
}

int main()
{
    freopen("name.dat", "r", stdin);
    string name;
    vector<string> vec;
    while(cin >> name){
        vec.push_back(name);
    }
    sort(vec.begin(), vec.end(), comp);

    for(vector<string>::iterator it = vec.begin(); it != vec.end(); it++) cout << *it << endl;
    return 0;

}
