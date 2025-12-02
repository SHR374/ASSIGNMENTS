#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int V = 5;
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    vector<int> key(V, INT_MAX), parent(V, -1);
    vector<bool> mstSet(V, false);
    key[0] = 0;

    for (int count = 0; count < V-1; count++) {
        int u = -1;
        for (int i=0;i<V;i++)
            if(!mstSet[i] && (u==-1 || key[i]<key[u])) u=i;

        mstSet[u] = true;
        for (int v=0; v<V; v++)
            if(graph[u][v] && !mstSet[v] && graph[u][v]<key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
    }

    cout << "Edges in MST (Prim):\n";
    for (int i=1;i<V;i++)
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << "\n";
}
