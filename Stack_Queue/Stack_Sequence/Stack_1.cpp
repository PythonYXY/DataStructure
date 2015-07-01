#include <iostream>
#include <stdlib.h>

using namespace std;

class _Stack
{
public:
    _Stack(){maxSize = 100; top = 0; elem = new int[maxSize];}
    ~_Stack() {delete [] elem;}
    bool Push(int x);
    int Pop();
    bool isEmpty();
    int getTop();
    int getSize();

private:
    int * elem;
    int top;
    int maxSize;
};

bool _Stack::Push(int x)
{
    if(top == maxSize) return false;
    elem[top] = x;
    top++;
    return true;
}

int _Stack::Pop()
{
    if(isEmpty()) exit(1);

    return elem[top--];
}

bool _Stack::isEmpty()
{
    if(top == 0) return true;
    return false;
}

int _Stack::getTop()
{
    if(isEmpty()) exit(1);
    return elem[top - 1];
}

int _Stack::getSize()
{
    return top;
}

int main()
{
    _Stack st;
    st.Push(100);
    st.Push(200);
    st.Push(300);
    cout << st.getTop() << endl;
    cout << st.getSize() << endl;
    st.Pop();
    cout << st.getTop();
	cout << endl;
    return 0;
}
