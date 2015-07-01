#include <iostream>
#include <map>
#include <string>
#include <cstdio>

using namespace std;

const string letter = "abcdefghijklmnopqrstuvwxyz";
const string code[26] = {"1110", "110000", "01001", "11111", "100", "00101", "110011", "0110",
                         "1011", "001001011", "0010011", "11110", "00111", "1010", "1101", "110001",
                         "001001001", "0101", "0111", "000", "01000", "001000", "00110", "001001010",
                         "110010", "001001000"};

int main()
{
    freopen("code.txt", "w", stdout);
    map<char, string> m1;

    for(int i = 0; i < 26; i++){
        m1.insert(pair<char, string>(letter[i], code[i]));
    }

    string text;
    cin >> text;

    int j = 0;
    while(text[j] != '\0'){
        cout << (m1.find(text[j++])) -> second;
    }
    return 0;
}
