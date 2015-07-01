#include <iostream>
#include <cstdio>
using namespace std;

struct LinkNode
{
    int data;
    LinkNode * node;
    LinkNode(LinkNode * temp = NULL) {node = temp;}
    LinkNode(int x, LinkNode * temp = NULL) {data = x; node = temp;}
};


class LList
{
public:
    LList(){first = new LinkNode;}
    ~LList(){delete first;}
    void Insert(int i, int x);
    int Search(int x);

private:
    LinkNode * first;
};

void LList::Insert(int i, int x)
{
    LinkNode * current = first;
    while(i--) current = current -> node;

    LinkNode * newn = new LinkNode(x);

    newn -> node = current -> node;
    current -> node = newn;

}


int LList::Search(int x)
{
    LinkNode * current = first;
    int i = 0;
    while(current -> data != x && current -> node != NULL) {current = current -> node; i++;}
    return i;

}


int main()
{
    freopen("nums.dat", "r", stdin);
    int x;
    LList lst;
    for(int i = 0; i < 10000; i++){
        cin >> x;
        lst.Insert(i, x);
    }
    cout << lst.Search(8003);
    return 0;
}
