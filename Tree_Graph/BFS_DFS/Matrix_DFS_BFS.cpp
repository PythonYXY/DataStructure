#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define INF 1000000000
const int MaxNode = 9;

int edge[MaxNode][MaxNode];
bool visited[MaxNode];


int getNext(int v)
{
    if(v != -1){
        for(int col = 0; col < MaxNode; col++){
            if(!visited[col] && edge[v][col] > 0 && edge[v][col] < INF) return col;
        }
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
    for(int i = 0; i < MaxNode; i++){
        for(int j = 0; j < MaxNode; j++){
            cin >> edge[i][j];
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
