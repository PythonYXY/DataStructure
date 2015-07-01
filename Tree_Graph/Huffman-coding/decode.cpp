#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

string arr_letter = "abcdefghijklmnopqrstuvwxyz";
double arr_freq[26] = {8.167, 1.492, 2.782, 4.253, 12.702, 2.228, 2.015,
                       6.094, 6.966, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507,
                       1.929, 0.095, 5.987, 6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974, 0.074};
struct BinTree;
vector<BinTree *>vec;


struct Letter
{
    char letter;
    double freq;
};
struct BinTree
{
    BinTree * left, * right;
    Letter data;
    BinTree(BinTree * tmpLeft = NULL, BinTree * tmpRight = NULL):
        left(tmpLeft), right(tmpRight) {}
    BinTree(Letter tmp_data, BinTree * tmpLeft = NULL, BinTree * tmpRight = NULL):
        data(tmp_data), left(tmpLeft), right(tmpRight) {}
};

bool comp(BinTree * trie1, BinTree * trie2)
{
    return (trie1 -> data).freq < (trie2 -> data).freq;
}

BinTree * Huffman_trie()
{
    while(true){
        BinTree * trie1 = vec[0];
        BinTree * trie2 = vec[1];
        vec.erase(vec.begin());
        vec.erase(vec.begin());
        Letter tmp;
        tmp.freq = (trie1 -> data).freq + (trie2 -> data).freq;
        BinTree * newt = new BinTree(tmp, trie1, trie2);
        if(vec.size() == 0) return newt;
        vec.push_back(newt);
        sort(vec.begin(), vec.end(), comp);
    }
}



int main()
{
    freopen("code.txt", "r", stdin);

    for(int i = 0; i < 26; i++){
        Letter tmp;
        tmp.letter = arr_letter[i];
        tmp.freq = arr_freq[i];
        BinTree * tmp_tree = new BinTree(tmp);
        vec.push_back(tmp_tree);
    }


    sort(vec.begin(), vec.end(), comp);
    BinTree * obj = Huffman_trie();

    string text;
    cin >> text;
    int i = 0;
    while(text[i] != '\0'){

        BinTree * tmp = obj;
        while(tmp -> left != NULL && tmp -> right != NULL){
            if(text[i] == '0') {tmp = tmp -> left;}
            else {tmp = tmp -> right;}
            i++;
        }
        cout << (tmp -> data).letter;

    }

    return 0;
}
