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

void dfsUtil(int src, vector<pair<int,int>> G[], vector<bool> &visited)
{
    visited[src] = true;
    
    for(int i=0; i<G[src].size(); i++)
    {
        int child = G[src][i].F;
        
        if(visited[child]) continue;
        
        dfsUtil(child, G, visited);
    }
}

void transpose_my_graph(int V, vector<pair<int,int>> G[], vector<pair<int,int>> _G[])
{
    for(int u=0; u<V; u++)
    {
        for(int i=0; i<G[u].size(); i++)
        {
            int child = G[u][i].F;
            int wg  = G[u][i].S;
            
            _G[child].push_back({u,wg});
        }
    }
}

bool isSCC(vector<pair<int,int>> G[], int V)
{
    vector<bool> visited(V, false);
    
    dfsUtil(0, G, visited);
    for(int i=0; i<V; i++)
        if(!visited[i]) return false;
    
    vector<pair<int,int>> _G[V];
    transpose_my_graph(V, G, _G);
    
    visited.resize(V, false);
    dfsUtil(0, _G, visited);
    for(int i=0; i<V; i++)
        if(!visited[i]) return false;
    
    return true;
}

int main() {
    
    // https://ide.geeksforgeeks.org/XwrhIcgix8
    /* Connectivity Set 2: Kosaraju using DFS | Check if a graph is strongly connected 
       1. Strongly connected if there is a path between any two pair of vertices
       2. For undirected graph apply BFS/DFS to check
       3. For Directed Graph Only use this Algorithm
       4. Steps:
          Graph1 A->B->C->A, Graph2 A->B->C->B
          >> 1. Apply DFS on Graph
          >> 2. Check every node is visited or not
          Reverse Graph or Transpose of Graph
          Graph1' A<-B<-C<-A, Graph2' A<-B<-C<-B
          >> 1. Apply DFS on Graph
          >> 2. Check every node is visited or not
    */
    
    int V; cin >> V;
    vector<pair<int,int>> G[V];
    vector< pair<int, pair<int,int>> > Edges;
    
    int E; cin >> E;
    for(int i=0; i<E; i++)
    {
        int s,e,w; cin >> s >> e >> w;
        G[s].push_back({e,w});
        //G[e].push_back({s,w});
        
        Edges.push_back( {w, {s,e}} );
    }
    
    cout << "print_graph" << endl; 
    print_graph(G, V);
    
    if(isSCC(G, V)) cout << "Yes SCC\n";
    else cout << "No SCC\n";
    
    return 0;
}