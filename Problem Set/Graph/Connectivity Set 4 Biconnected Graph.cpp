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


bool util_BC(vector<pair<int,int>> G[], int src,
             vector<bool> &visited, vector<int> &low, vector<int> &discovery,
             vector<int> &parent, vector<bool> &AP, int &t
            )
{
    visited[src] = true;
    int child_count = 0;
    discovery[src] = low[src] = ++t;
    
    for(int i=0; i<G[src].size(); i++)
    {
        int child = G[src][i].F;
        if(!visited[child])
        { 
            child_count++;
            parent[child] = src;
        
            if(util_BC(G, child, visited, low, discovery, parent, AP, t)) return true;
        
            low[src] = min(low[src], low[child]);
        
            // condition 1
            if(parent[src] == -1 && child_count>1)
            {    AP[src] = true; return true; }
            //condition 2
            if(parent[src] != -1 && low[child] >= discovery[src])
            {    AP[src] = true; return true; }
            
        }
        else if(child != parent[src])
            low[src] = min(low[src], discovery[child]);
    }
    
    return false;
}


bool isBiconnectedGraph(vector<pair<int,int>> G[], int V)
{
    vector<int> discovery(V, INT_MAX);
    vector<int> low(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> visited(V, false);
    vector<bool> AP(V, false);
    
    int t=0;
    if(util_BC(G, 0, visited, low, discovery, parent, AP, t)) return false;
    
    for(int i=0; i<V; i++)
    {
        if(AP[i]) return false;
    }
    
    return true;
}


int main() {
    
    // https://ide.geeksforgeeks.org/GFRa4mbjiX
    /* Connectivity Set 4: Biconnected Graph
       1. Strongly connected if there is a path between any two pair of vertices
       2. A vertex in an undirected connected graph is an articulation point (or cut vertex)
          iff removing it (and edges through it) disconnects the graph
       3. Conditions
          >> It is connected, i.e. it is possible to reach every vertex from every 
             other vertex, by a simple path. 
          >> Even after removing any vertex the graph remains connected. 
       
       4. Array:
           discovery array: store the time when a node is visited
           low discovery time of a node low[u] = min(discovery[u], discovery[w])
           those nodes are a part of scc will have equal discovery time 
    */
    
    int t; cin >>t;
    while(t--)
    {
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
    
    if(isBiconnectedGraph(G, V)) cout << "Yes\n";
    else cout << "No\n";
    }
    return 0;
}