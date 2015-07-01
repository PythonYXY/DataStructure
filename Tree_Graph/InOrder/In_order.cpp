#include <iostream>
using namespace std;

struct BinTree
{
    int data;
    BinTree * left, * right;
    BinTree(BinTree * tmpLeft = NULL, BinTree * tmpRight = NULL):
        left(tmpLeft), right(tmpRight) {}
    BinTree(int num, BinTree * tmpLeft = NULL, BinTree * tmpRight = NULL):
        data(num), left(tmpLeft), right(tmpRight) {}
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

void inOrder(BinTree *&root)
{
    if(root == NULL) return;
    else{
        inOrder(root -> right);
        cout << root -> data << ' ';
        inOrder(root -> left);
    }
}

int main()
{
    BinTree *root = new BinTree;
    construct(root);
    inOrder(root);
    return 0;
}
