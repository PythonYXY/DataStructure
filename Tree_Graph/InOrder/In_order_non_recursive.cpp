#include <iostream>
#include <stack>
//#include <cstdio>
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
    stack<BinTree *> treeStack;
    BinTree * pr = root;
    do{
        while(pr != NULL){
            treeStack.push(pr);
            pr = pr -> left;
        }
        if(!treeStack.empty()){
            pr = treeStack.top();
            treeStack.pop();
            cout << pr -> data << ' ';
            pr = pr -> right;
        }
    }while(pr!= NULL || !treeStack.empty());
}

int main()
{
    //freopen("test.txt", "r", stdin);
    BinTree *root = new BinTree;
    construct(root);
    inOrder(root);
    return 0;
}
