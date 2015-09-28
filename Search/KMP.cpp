#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

const int MAX = 1e6 + 5;

string tar;
string src;

int NEXT[MAX];

void GetNEXT() {
    int j = 0, k = -1;
    int len = tar.size();
    NEXT[0] = -1;
    while (j < len) {
        if (k == -1 || tar[j] == tar[k]) {
            j++; k++;
            NEXT[j] = k;
        } else {
            k = NEXT[k];
        }
    }
}

int main() {
    freopen("data.txt", "r", stdin);
    int n;
    cin >> n;
    while (n--) {
        cin >> tar >> src;
        GetNEXT();
        // for (int i = 0; i <= tar.size(); i++) cout << NEXT[i] << ' ';
        // cout << endl;
        // continue;
        int t = 0, s = 0;
        int ans = 0;
        int src_len = src.size(), tar_len = tar.size();
        while (s < src_len) {
            if (t == -1 || src[s] == tar[t]) {s++; t++;}
            else t = NEXT[t];

            if (t == tar_len) {ans++; t = NEXT[tar_len];}
        }
        cout << ans << endl;
    }
    return 0;
}
