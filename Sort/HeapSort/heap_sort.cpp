#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_SIZE = 10005;

class Heap
{
public:
    Heap() {sz = 0;}
    void push(int x);
    int pop();
    bool isEmpty() {return sz == 0 ? true : false;}
private:
    int heap[MAX_SIZE], sz;
};


void Heap::push(int x)
{
    int i = sz++;

    while(i > 0){
        int p  = (i - 1) / 2;

        if(heap[p] <= x) break;

        heap[i] = heap[p];
        i = p;
    }
    heap[i] = x;
}

int Heap::pop()
{
    int res = heap[0];

    int x = heap[--sz];

    int i = 0;
    while(i * 2 + 1 < sz){
        int a = i * 2 + 1, b = i * 2 + 2;
        if(b < sz && heap[a] > heap[b]) a = b;

        if(heap[a] >= x) break;

        heap[i] = heap[a];
        i = a;
    }
    heap[i] = x;
    return res;
}

int main()
{
    freopen("data.dat", "r", stdin);
    freopen("Heap_sort_result.dat", "w", stdout);

    int x;
    Heap hp;
    while(cin >> x){
        hp.push(x);
    }
    while(!hp.isEmpty()){
        cout << hp.pop() << endl;
    }
    return 0;
}
