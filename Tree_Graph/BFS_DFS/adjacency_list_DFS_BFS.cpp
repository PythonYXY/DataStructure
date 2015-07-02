#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define INF 1000000000

using namespace std;

const int MAX_SIZE = 9;
bool visited[MAX_SIZE];

struct node
{
    int data;
    node * next;
    node(): next(NULL) {}
};

node * al[MAX_SIZE];
int edge[MAX_SIZE][MAX_SIZE];

int getNext(int v)
{
    if(v != -1){
        node *p = al[v] -> next;
        while(p != NULL && visited[p -> data]) p = p -> next;
        if(p != NULL) return p -> data;
    }
    return -1;
}


void DFS(int v)
{
    cout << v << ' ';
    visited[v] = true;
    v = getNext(v);
    while(v != -1){
        if(!visited[v]) DFS(v);
        v = getNext(v);
    }
}
void BFS(int v)
{
    cout << v << ' ';
    visited[v] = true;

    queue<int> que;
    que.push(v);

    while(!que.empty()){
        v = que.front();
        que.pop();
        v = getNext(v);
        while(v != -1){
            if(!visited[v]){
                cout << v << ' ';
                visited[v] = true;
                que.push(v);
            }
            v = getNext(v);
        }
    }
}


int main()
{
    freopen("MatrixGraph.dat", "r", stdin);
    for(int i = 0; i < MAX_SIZE; i++){
        for(int j = 0; j < MAX_SIZE; j++){
            cin >> edge[i][j];
        }
    }
    for(int i = 0; i < MAX_SIZE; i++){
        al[i] = new node;
        al[i] -> data = i;
        node * tmp = al[i];
        for(int j = 1; j < MAX_SIZE; j++){
            if(edge[i][j] > 0 && edge[i][j] < INF){
                node * newn = new node;
                newn -> data = j;
                tmp -> next = newn;
                tmp = tmp -> next;
            }
        }
    }

    memset(visited, false, sizeof(visited));
    cout << "The result of DFS: ";
    DFS(0);
    cout << endl;

    memset(visited, false, sizeof(visited));
    cout << "The result of BFS: ";
    BFS(0);

    return 0;
}
