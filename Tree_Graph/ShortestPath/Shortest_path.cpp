#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <cstdio>
#include <stdlib.h>

using namespace std;

#define INF 1000000000
const int MAX_SIZE = 9;

struct INFO
{
    string name;
    int id;
    string description;
};

map<int, INFO> mp;

int cost[MAX_SIZE][MAX_SIZE];
int d[MAX_SIZE];
bool used[MAX_SIZE];

int prev[MAX_SIZE];

void dijkstra(int s)
{
    fill(d, d + MAX_SIZE, INF);
    fill(used, used + MAX_SIZE, false);
    fill(prev, prev + MAX_SIZE, -1);
    d[s] = 0;

    while(true){
        int v = -1;
        for(int u = 0; u < MAX_SIZE; u++){
            if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
        }

        if(v == -1) break;
        used[v] = true;

        for(int u = 0; u < MAX_SIZE; u++){
            if(d[u] > d[v] + cost[v][u]){
                d[u] = d[v] + cost[v][u];
                prev[u] = v;
            }
        }
    }
}





int main()
{
    freopen("map_of_sites.dat", "r", stdin);
    for(int i = 0; i < MAX_SIZE; i++){
        for(int j = 0; j < MAX_SIZE; j++){
            cin >> cost[i][j];
        }
    }
    vector<int> path;
    int s, e;
    s = 2;
    e = 5;
    dijkstra(s);

    for(int t = e; t != -1; t = prev[t]) path.push_back(t);
    cout << "The shortest path from " << s << " to " << e << ": ";
    for(int i  = path.size() - 1; i >= 0; i--) cout << path[i] << ' ';
    cout << endl << "The cost: " << d[e];

    return 0;
}
