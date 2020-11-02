#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define F first
#define S second

vector<vector<int>> min_dist;
vector<vector<int>> next_hop;

void print_graph(vector<pair<int,int>> G[], int V)
{
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<G[i].size(); j++)
            cout << i << " ->- " << G[i][j].first << " wg: " << G[i][j].second << endl; 
    }
}

bool isPath(vector<pair<int,int>> G[], int src, int dest, vector<bool> &visited)
{
    if(src == dest) return true;
    visited[src] = true;
    
    for(int i=0; i<G[src].size(); i++)
    {
        int v = G[src][i].F;
        if(visited[v]) continue;
        if(isPath(G, v, dest, visited)) return true;
    }
    
    return false;
}

int main() {
    
    // https://ide.geeksforgeeks.org/oQ99kM3fuL
    /* Connectivity Set 1: Find if there is a path between two vertices in a directed /undirected graph
        1. The time complexity remains O(V + E)
        2. The time complexity remains O(V)
        3. Apply BFS/DFS
    */
    
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
    
    int q; cin >> q;
    while(q--)
    {
        vector<bool> visited(V, false);
        int u,v; cin >> u >> v;
        if(isPath(G,u,v, visited)) cout << "Yes\n";
        else cout << "No\n";
    }
    
    return 0;
}