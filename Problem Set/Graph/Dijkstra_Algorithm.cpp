#include <bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

void print_graph(vector<pair<int,int>> G[], int V)
{
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<G[i].size(); j++)
            cout << i << " ->- " << G[i][j].first << " wg: " << G[i][j].second << endl; 
    }
}

int find_minValue(int dist[], bool sptSet[], int V)
{
    int min_val = INT_MAX, index = -1;
    for(int i=0; i<V; i++)
    {
        if(!sptSet[i] && min_val > dist[i])
        {
            min_val = dist[i]; 
            index = i;
        }
    }
    return index;
}

void basic_dijkstra(vector<pair<int,int>> G[], int src, int V)
{
    int dist[V]; bool sptSet[V]; // distance and shortest path tree set
    
    for(int i=0; i<V; i++) 
    { 
        dist[i] = INT_MAX; 
        sptSet[i] = false;
    }
    
    dist[src] = 0;
    
    // V-1 edges possible 
    for(int i=0; i<V-1; i++)
    {
        int u = find_minValue(dist, sptSet, V);
        sptSet[u] = true;
        
        for(int j=0; j<G[u].size(); j++)
        {
            int v = G[u][j].first;
            int wg = G[u][j].second;
            
            if(!sptSet[v] && dist[v] > dist[u] + wg )
                dist[v] = dist[u] + wg;
        }
    }
    
    for(int i=0; i<V; i++)
        cout << i << " " << dist[i] << endl;
    
}

void dijkstra(vector<pair<int,int>> G[], int src, int V)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq; // min heap
    vector<int> dist(V, INT_MAX);

    pq.push({0,src});
    dist[src] = 0;
    
    while(!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i].first;
            int wg = G[u][i].second;
            
            if(dist[v] > dist[u] + wg)
            {
                dist[v] = dist[u] + wg;
                pq.push({dist[v], v});
            }
        }
    }
    
    for(int i=0; i<V; i++)
        cout << i << " " << dist[i] << endl;
}

int main() {
    
    // https://ide.geeksforgeeks.org/X97B3kBIlb
    // Dijkstra Algorithm
    // 1. The time complexity remains O(ELogV))
    // 2. Didnot work for Negative wg
    
    
    int V; cin >> V;
    vector<pair<int,int>> G[V];
    
    int E; cin >> E;
    for(int i=0; i<E; i++)
    {
        int s,e,w; cin >> s >> e >> w;
        G[s].push_back({e,w});
        G[e].push_back({s,w});
    }
    
    int src; cin >> src;
    
    cout << "print_graph" << endl; 
    print_graph(G, V);
    cout << "basic_dijkstra" << endl;
    basic_dijkstra(G, src, V);
    cout << "dijkstra" << endl;
    dijkstra(G, src, V);
    
    return 0;
}