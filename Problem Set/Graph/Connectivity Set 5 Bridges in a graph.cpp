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


void util_bridges(vector<pair<int,int>> G[], int src,
             vector<bool> &visited, vector<int> &low,
             vector<int> &discovery, vector<int> &parent,
             int &t
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
        
            util_bridges(G, child, visited, low, discovery, parent, t);
        
            low[src] = min(low[src], low[child]);
        
            // condition 1
            if(low[child] > discovery[src])
                cout << src << " " << child << endl;
        }
        else if(child != parent[src])
            low[src] = min(low[src], discovery[child]);
    }
}


void print_bridges(vector<pair<int,int>> G[], int V)
{
    cout << "Print Bridge or critical connections\n";
    vector<int> discovery(V, INT_MAX);
    vector<int> low(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> visited(V, false);
    
    int t=0;
    for(int i=0; i<V; i++)
    {
        if(visited[i]) continue;
        
        util_bridges(G, i, visited, low, discovery, parent, t);
    }
    
    cout << "Process End\n";
}


int main() {
    
    // https://ide.geeksforgeeks.org/tK3lPJY1L6
    // https://www.geeksforgeeks.org/bridge-in-a-graph/
    /* Connectivity Set 5: Bridges in a graph (or Cut Edge)
    1. An edge in an undirected connected graph is a bridge 
       iff removing it disconnects the graph
    2. In a wired computer network, an articulation point indicates 
       the critical computers and a bridge indicates the critical wires or connections
    3. How to find all bridges in a given graph?
        Method 1 O(E*(V+E))
          3.1 Remove each edges
          3.2 apply bfs/dfs check whetjer graph is connected or not
          3.3 Add edge again to the graph
          
        Method 2 O(V+E) DFS Tree
        Idea: subtree u -- U --- V -- v subtree 
              if we remove U --- V edge no way v could reach nodes of subtree u
        U--V as Bridges, Condition: low[v] > discovery[u]
        Note: low[v] indicates earliest visited vertex reachable from subtree rooted with v.
          
          3.1 DFS Tree
          3.2 U -- V
            >> DFS tree rooted(U)
            >> if low[child] > discovery[parent] then edge is Bridge 
          
        4. Array
           discovery array: store the time when a node is visited
           low discovery time of a node low[v] = min(low[u], low[v])
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
    
    print_bridges(G, V);
    }
    return 0;
}