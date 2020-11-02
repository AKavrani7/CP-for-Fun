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

int find(int i, vector<int> parent)
{
    if(parent[i] == i)
        return i;
    
    return find(parent[i], parent);
}

void kruskal_MST(vector<pair<int,int>> G[], vector<pair<int, pair<int,int>>> Edges, int V, int E)
{
    sort(Edges.begin(), Edges.end());
    
    vector<pair< pair<int,int>, int> > res_mst(V-1);
    vector<int> parent(V), rank(V);
    for(int i=0; i<V; i++)
    {
        parent[i] = i; 
        rank[i] = 0;
    }
    
    int e=0, i=0; // current edge count and current check ith edge
    while(e < V-1 && i<E)
    {
        int src = Edges[i].second.first;
        int dest = Edges[i].second.second;
        int wg = Edges[i].first;
        
        int p_src = find(src, parent);
        int p_dest = find(dest, parent);
        
        if(p_src != p_dest)
        {
            res_mst[e] = {{src,dest}, wg};
            e++;
            
            if(rank[p_src] < rank[p_dest])
                swap(p_src, p_dest);
            
            parent[p_dest] = p_src;
            rank[p_src]++;
        }
        
        i++;
    }
    
    
    for(int i=0; i<V-1; i++)
    {
        cout << res_mst[i].first.first << " ->- "  
                << res_mst[i].first.second << " w: "  
                    << res_mst[i].second << endl; 
    }
}


int main() {
    
    // https://ide.geeksforgeeks.org/bWKWn828sd
    // Kruskal_MST Algorithm
    // 1. The time complexity remains O(ELogV + VLogE)
    // 2. Sorting of edges takes O(ELogE) time. After sorting, we iterate through 
    // all edges and apply find-union algorithm. The find and union operations 
    // can take atmost O(LogV) time. So overall complexity is O(ELogE + ELogV) time.
    
    
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
    
    int src; cin >> src;
    
    cout << "print_graph" << endl; 
    print_graph(G, V);
    cout << "Kruskal_MST" << endl;
    kruskal_MST(G, Edges, V, E);
    
    return 0;
}