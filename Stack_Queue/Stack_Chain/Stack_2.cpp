#include <iostream>
#include <stdlib.h>

using namespace std;

struct LinkNode
{
    int data;
    LinkNode * node;
    LinkNode(LinkNode * nd = NULL) {node = nd;}
    LinkNode(int x, LinkNode * nd = NULL) : data(x), node(nd) {}
};
class _Stack
{
public:
    _Stack() {top = new LinkNode;}
    ~_Stack() {makeEmpty();}
    bool Push(int x);
    int Pop();
    int getTop();
    bool isEmpty() {return top == NULL ? true : false;}
    bool makeEmpty();
    int getSize();
    friend ostream & operator << (ostream & os, _Stack & st);

private:
    LinkNode * top;
};


bool _Stack::Push(int x)
{
    top = new LinkNode(x, top);
    return true;
}


int _Stack::Pop()
{
    if(isEmpty()) exit(1);
    LinkNode * temp = top;
    int num = top -> data;
    top = top -> node;
    delete temp;
    return num;
}

int _Stack::getTop()
{
    if(isEmpty()) exit(1);
    return top -> data;
}

bool _Stack::makeEmpty()
{
    while(top != NULL){
        LinkNode * temp = top;
        top = top -> node;
        delete temp;
    }
    return true;
}

int _Stack::getSize()
{
    int k = 0;
    LinkNode * temp = top;
    while(temp -> node != NULL){
        k++;
        temp = temp -> node;
    }
    return k;
}

ostream & operator << (ostream & os, _Stack &st)
{
    int i = 1;
    LinkNode * temp = st.top;
    while(temp -> node != NULL){
        os << i << " : " << temp -> data << endl;
        temp = temp -> node;
        i++;
    }
    return os;
}



int main()
{
    _Stack st;
    st.Push(100);
    st.Push(200);
    st.Push(300);
    st.Pop();
    st.Pop();
    cout << st.getTop() << endl;
    cout << st;
    cout << st.getSize() << endl;
    exit(1);
}
