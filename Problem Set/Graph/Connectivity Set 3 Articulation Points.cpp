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


void util_AP(vector<pair<int,int>> G[], int src, int V,
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
        
            util_AP(G, child, V, visited, low, discovery, parent, AP, t);
        
            low[src] = min(low[src], low[child]);
        
            // condition 1
            if(parent[src] == -1 && child_count>1)
                AP[src] = true;
            //condition 2
            if(parent[src] != -1 && low[child] >= discovery[src])
                AP[src] = true;
        }
        else if(child != parent[src])
            low[src] = min(low[src], discovery[child]);
    }
}


void print_articulation_point(vector<pair<int,int>> G[], int V)
{
    vector<int> discovery(V, INT_MAX);
    vector<int> low(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> visited(V, false);
    vector<bool> AP(V, false);
    
    int t=0;
    for(int i=0; i<V; i++)
    {
        if(visited[i]) continue;
        
        util_AP(G, i, V, visited, low, discovery, parent, AP, t);
    }
    
    bool check = false;
    for(int i=0; i<V; i++)
    {
        if(AP[i]){ check = true; cout << i << " ";}
    }
    
    if(!check) cout << "No AP GOOD Graph";
    cout << endl;
}


int main() {
    
    // https://ide.geeksforgeeks.org/aZGEwCnEUO
    /* Connectivity Set 3: Articulation Points (or Cut Vertices) in a Graph)
       1. Strongly connected if there is a path between any two pair of vertices
       2. A vertex in an undirected connected graph is an articulation point (or cut vertex)
          iff removing it (and edges through it) disconnects the graph
       3. How to find articulation point
          Method 1 O(V*(V+E))
          3.1 Remove each vertex and edges asscoiated with it
          3.2 apply bfs/dfs check whetjer graph is connected or not
          3.3 Add vertex again to the graph
          Method 2 O(V+E) DFS Tree
          3.1 DFS 
          3.2 u is AP
                >> u is root of dfs tree and has more than one child.
                >> u is not rott of dfs tree and u is the only way to reach its child node v.
          
        4. Idea:
           for second case
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
    
    print_articulation_point(G, V);
    }
    return 0;
}