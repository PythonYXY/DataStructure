#include <iostream>
#include <queue>
#include <stack>
using namespace std;


struct BinTree
{
    BinTree * left, * right;
    int data;
    BinTree(BinTree * tmpLeft = NULL, BinTree * tmpRight = NULL):
        left(tmpLeft), right(tmpRight) {}
    BinTree(int tmp_data, BinTree * tmpLeft = NULL, BinTree * tmpRight = NULL):
        data(tmp_data), left(tmpLeft), right(tmpRight) {}
};


void construct(BinTree * &obj)
{
    int c;
    cin >> c;
    if(c == -1) return;
    else{
        BinTree * tmp = new BinTree(c);
        obj = tmp;
        construct(obj -> left);
        construct(obj -> right);
    }
}


int NodeNum(BinTree * root)
{
    if(root == NULL) return 0;
    else return 1 + NodeNum(root -> left) + NodeNum(root ->right);
}

int main()
{
    BinTree * obj = new BinTree();
    construct(obj);
    cout << NodeNum(obj) << endl;
    return 0;
}
