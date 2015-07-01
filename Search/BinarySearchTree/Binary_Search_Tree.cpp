#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

// The time complexity of Insert() and Remove() is O(log(n))

struct BinSrchTree
{
    int data;
    BinSrchTree * left, * right;
    BinSrchTree(BinSrchTree * tmpLeft = NULL, BinSrchTree * tmpRight = NULL): left(tmpLeft), right(tmpRight) {}
    BinSrchTree(int tmpData, BinSrchTree * tmpLeft = NULL, BinSrchTree * tmpRight = NULL): data(tmpData),
        left(tmpLeft), right(tmpRight) {}

    friend ostream & operator << (ostream & os, BinSrchTree * root);
};


void Insert(int x, BinSrchTree * &root)
{
    if(root == NULL){
        BinSrchTree * tmpTree = new BinSrchTree(x);
        root = tmpTree;
        return;
    }
    else if (x < root -> data){
        Insert(x, root -> left);
    }
    else if(x > root -> data){
        Insert(x, root -> right);
    }

}


bool Remove(int x, BinSrchTree * &root)
{
    BinSrchTree * tmpTree;
    if (root != NULL){
        if(x < root -> data) Remove(x, root ->left);
        else if(x > root -> data) Remove(x, root -> right);
        else if(root -> right != NULL && root ->right != NULL){

            tmpTree = root -> right;
            while(tmpTree -> left != NULL) tmpTree = tmpTree -> left;
            root -> data = tmpTree -> data;
            Remove(tmpTree -> data, root -> right);
        }
        else {
            tmpTree = root;
            if(tmpTree -> left == NULL) root = root -> right;
            else root = root ->left;
            delete tmpTree;
            return true;
        }
    }
    return false;
}


ostream & operator << (ostream & os, BinSrchTree * root)
{
    queue<BinSrchTree *> que;
    que.push(root);
    while(!que.empty()){
        BinSrchTree * tmpTree = que.front();
        que.pop();
        os << tmpTree ->data << ' ';
        if(tmpTree -> left != NULL) que.push(tmpTree -> left);
        if(tmpTree -> right != NULL) que.push(tmpTree -> right);
    }
    return os;
}

int main()
{
    freopen("data.dat", "r", stdin);
    BinSrchTree * root;
    int x;
    root = NULL;
    while(cin >> x) Insert(x, root);
    cout << root << endl;
    Remove(5, root);
    cout << root << endl;
    return 0;
}
