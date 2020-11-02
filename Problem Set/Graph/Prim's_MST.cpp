#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define F first
#define S second

void print_graph(vector<pair<int,int>> G[], int V)
{
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<G[i].size(); j++)
            cout << i << " ->- " << G[i][j].first << " wg: " << G[i][j].second << endl; 
    }
}

void Prims_MST(vector<pair<int,int>> G[], int V)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> mst(V, false); vector<int> key(V, INT_MAX), parent(V,-1);
    
    int src = 0;
    key[src] = 0;
    parent[src] = src;
    
    pq.push({0, src});
    
    while(!pq.empty())
    {
        auto tmp = pq.top(); pq.pop();
        int u = tmp.S;
        int d = tmp.F;
        
        mst[u] = true;
        
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i].F;
            int w = G[u][i].S;
            if(!mst[v] && key[v] > d + w)
            {
                parent[v] = u;
                key[v] = d + w;
                pq.push({d+w, v});
            }
        }
    }
    
    for(int i=0; i<V; i++)
    {
        cout << parent[i] << " ->- " << i << " wg: " << key[i] << endl; 
    }
}


int main() {
    
    // https://ide.geeksforgeeks.org/y8rnSxxP0y
    // Prims MST Algorithm
    // 1. The time complexity remains O(ELogV)
    // 2. Two sets are maintained, one set contains list of vertices already 
    //    included in MST, other set contains vertices not yet included.
    // 3. The idea is to traverse all vertices of graph using BFS 
    //    and use a Min Heap to store the vertices not yet included in MST. 
    //    Min Heap is used as a priority queue to get the minimum weight edge from the cut.
    
    int V; cin >> V;
    vector<pair<int,int>> G[V];
    vector< pair<int, pair<int,int>> > Edges;
    
    int E; cin >> E;
    for(int i=0; i<E; i++)
    {
        int s,e,w; cin >> s >> e >> w;
        G[s].push_back({e,w});
        G[e].push_back({s,w});
        
        Edges.push_back( {w, {s,e}} );
    }
    
    cout << "print_graph" << endl; 
    print_graph(G, V);
    cout << "Prims MST" << endl;
    Prims_MST(G, V);
    
    return 0;
}