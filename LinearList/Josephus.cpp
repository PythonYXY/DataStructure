#include <iostream>
#include <stdlib.h>

using namespace std;

struct LinkNode
{
    int data;
    LinkNode * node;
    LinkNode(int x): data(x) {}
};

class Josephus
{
public:
    Josephus(int x, int y, int z): n(x), s(y), m(z)  {first = new LinkNode(1); first -> node = first;}
    void Init();
    void Operate();
    void Result();

private:
    LinkNode * first;
    int n, m, s;
};

void Josephus::Init()
{
    LinkNode * current = first;
    for(int i = 2; i<= n; i++){
        LinkNode * temp = new LinkNode(i);
        temp -> node = current -> node;
        current -> node = temp;
        current = current -> node;
    }
}

void Josephus::Operate()
{
    LinkNode * current = first, * pre = NULL;
    int i, j;

    // The time complexity is O(m * (n-s))

    for(i = 1; i <= n - s; i++){
        if (m == 0 || m == 1) {cout << "Wrong input!" << endl;; exit(1);}
        for(j = 1; j < m; j++){pre = current; current = current -> node;}
        cout << current -> data << " is out." << endl;
        pre -> node = current -> node; delete current;
        current = pre -> node;
    }
    first = current;
}

void Josephus::Result()
{
    cout << endl << endl;
    LinkNode * current = first;
    do{
        cout << current -> data << ' ';
        current = current -> node;
    }while(current != first);
    cout << "is left." << endl << endl;
}


int main()
{
    int n, s, m;
    while(cin >> n >> s >> m && n != 0){
        Josephus J(n, s, m);
        J.Init();
        J.Operate();
        J.Result();
    }
    return 0;
}

