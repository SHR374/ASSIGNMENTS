#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};
struct DSU {
    vector<int> parent;
    DSU(int n) { parent.resize(n); for(int i=0;i<n;i++) parent[i]=i; }
    int find(int x) { return parent[x]==x?x:parent[x]=find(parent[x]); }
    void unite(int x,int y){ parent[find(x)] = find(y); }
};

int main() {
    int V = 4;
    vector<Edge> edges = {{0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}};
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){ return a.w < b.w; });

    DSU dsu(V);
    cout << "Edges in MST (Kruskal):\n";
    for(auto e: edges){
        if(dsu.find(e.u)!=dsu.find(e.v)){
            cout << e.u << " - " << e.v << " : " << e.w << "\n";
            dsu.unite(e.u,e.v);
        }
    }
}
