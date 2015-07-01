#include <iostream>
#include <stdlib.h>
#include <assert.h>
using namespace std;

struct LinkNode
{
    int data;
    LinkNode * node;
    LinkNode(LinkNode  * ptr = NULL) {node = ptr;}
    LinkNode(int num, LinkNode * ptr = NULL): data(num), node(ptr) {}
};

class Queue
{
public:
    Queue() {rear = new LinkNode(-1); rear -> node = rear;}
    void Push(int x);
    int Pop();
    bool isEmpty() {return rear == rear -> node ? true : false;}
    void makeEmpty();
private:
    LinkNode * rear;
};

void Queue::Push(int x)
{
    LinkNode * newn = new LinkNode(x);
    newn -> node = rear -> node;
    rear -> node = newn;
    rear = rear -> node;
}


int Queue::Pop()
{

    LinkNode *  first = rear -> node;
    LinkNode * temp = first -> node;
    if(temp == rear) rear = first;
    int num = temp -> data;
    first -> node = temp -> node;
    delete temp;
    return num;
}

void Queue::makeEmpty()
{
    LinkNode * first = rear -> node;
    while(first != first -> node){
        LinkNode * temp = first -> node;
        first -> node = temp -> node;
        delete temp;
    }
    rear = first;
}
int main()
{
    Queue que;
    if(que.isEmpty()) cout << "Yes" << endl;
    que.Push(100);
    que.Push(200);
    que.Pop();
    que.Pop();
    if(que.isEmpty()) cout << "Yes" << endl;
    return 0;
}
