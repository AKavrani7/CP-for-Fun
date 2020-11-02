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

void floyd_warshall(vector<pair<int,int>> G[], int V)
{
    min_dist.resize(V, vector<int>(V, INT_MAX));
    next_hop.resize(V, vector<int>(V, -1));
    
    for(int u=0; u<V; u++)
    {
        for(int j=0; j<G[u].size(); j++)
        {
            int v = G[u][j].F;
            int w = G[u][j].S;
            
            min_dist[u][v] = w;
            next_hop[u][v] = v;
        }
    }
    
    for(int k=0; k<V; k++)
    {
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                if(min_dist[i][k] == INT_MAX || min_dist[k][j] == INT_MAX)
                    continue;
                else if(min_dist[i][j] > min_dist[i][k] + min_dist[k][j])
                {
                    min_dist[i][j] = min_dist[i][k] + min_dist[k][j];
                    next_hop[i][j] = next_hop[i][k];
                }
            }
        }
    }
    
    
    for(int i=0; i<V; i++)
    {
        if(min_dist[i][i] < 0)
        {
            cout << "Graph Contain negative cycles" << endl;
        }
    }
    
    cout << "Hey no negative cycle Stay Safe!!" << endl;
}

void print_path(int u, int v)
{
    vector<int> path;
    
    if(min_dist[u][v] == INT_MAX)
    {
        cout << "No path exists" << endl;
        return;
    }
    
    path.push_back(u);
    while(u != v)
    {
        u = next_hop[u][v];
        path.push_back(u);
    }
    
    int i=0;
    for(i=0; i<path.size()-1; i++)
    {
        cout << path[i] << " ->- ";
    }
    
    cout << path[i] << endl;
}

int main() {
    
    // https://ide.geeksforgeeks.org/Fx3krrHGTE
    /* Floyd Warshall Algorithm
        1. The time complexity remains O(V^3)
        2. The problem is to find shortest distances between every pair of 
           vertices in a given edge weighted directed Graph/undirected Graph.
        3. Idea: if dist[i][j] > dist[i][k] + dist[k][j]
           Update: dist[i][j] = dist[i][k] + dist[k][j] 
        4. Source:
        >> https://cp-algorithms.com/graph/all-pair-shortest-path-floyd-warshall.html
        >> https://www.geeksforgeeks.org/detecting-negative-cycle-using-floyd-warshall/?ref=rp
        >> https://www.geeksforgeeks.org/finding-shortest-path-between-any-two-nodes-using-floyd-warshall-algorithm/?ref=rp
        5. Dijkstra vs Floyd Warshall 
            >> Dijkstra’s Algorithm is single-source shortest or SSSP algorithm
            >> Time complexity:  O(E log V) 
            >> To find  Dijskstra’s shortest path algorithm for finding all pair
            >> shortest paths by running it for every vertex. But time complexity of
            >> this would be O(VE Log V) which can go (V3 Log V) in worst case
            
            >> Unlike Dijkstra’s algorithm, Floyd Warshall can be implemented in a distributed system, 
            >> making it suitable for data structures such as Graph of Graphs (Used in Maps).
            >> Lastly Floyd Warshall works for negative edge but no negative cycle, 
            >> whereas Dijkstra’s algorithm don’t work for negative edges.
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
    
    floyd_warshall(G, V);
    
    int q; cin >> q;
    while(q--)
    {
        int u,v; cin >> u >> v;
        print_path(u,v);
    }
    
    return 0;
}