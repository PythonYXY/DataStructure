#include <iostream>
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
    void Delete(int i);
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

void LList::Delete(int i)
{
    LinkNode * current = first;
    while(i-- > 1) current = current -> node;

    LinkNode * temp = current -> node;
    current -> node = temp -> node;

    delete temp;
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
    // TEST CODE
    /**
    LList C;

    C.Insert(0, 100);
    C.Insert(1, 200);
    C.Insert(2, 300);
    cout << "The position of 300: " << C.Search(300) << endl;

    C.Delete(2);

    cout << "The position of 300: " << C.Search(300) << endl;
    **/

    return 0;
}





