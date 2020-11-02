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


void util_scc_heads(vector<pair<int,int>> G[], int src,
             vector<bool> &stack_member, vector<int> &low,
             vector<int> &discovery, stack<int> &st,
             int &t
            )
{
    stack_member[src] = true;
    discovery[src] = low[src] = ++t;
    st.push(src);
    
    for(int i=0; i<G[src].size(); i++)
    {
        int child = G[src][i].F;
        if(discovery[child] == INT_MAX)
        { 
            util_scc_heads(G, child, stack_member, low, discovery, st, t);
        
            low[src] = min(low[src], low[child]);
        
        }
        else if(stack_member[child] == true)
            low[src] = min(low[src], discovery[child]);
    }
    
    if(low[src] == discovery[src])
    {
        while(st.top() != src)
        {
            cout << st.top() << " ";
            stack_member[st.top()] = false;
            st.pop();
        }
        
        cout << st.top() << " \n";
        stack_member[st.top()] = false;
        st.pop();
    }
}


void print_SCC_heads(vector<pair<int,int>> G[], int V)
{
    cout << "Print SCC head\n";
    vector<int> discovery(V, INT_MAX);
    vector<int> low(V, INT_MAX);
    stack<int> st;
    vector<bool> stack_member(V, false);
    
    int t=0;
    for(int i=0; i<V; i++)
    {
        if(discovery[i] != INT_MAX) continue;
        
        util_scc_heads(G, i, stack_member, low, discovery, st, t);
    }
    
    cout << "Process End\n";
}


int main() {
    
    // https://ide.geeksforgeeks.org/107qugW9Z0
    // For Directed graph
    // https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/ 
    /* Connectivity Set 6: Tarjan’s Algorithm | To find Strongly Connected Components
    1. A graph can contain multiple Strongly Connected Components
    2. Facts:
       >> DFS search produces a DFS tree/forest
       >> Strongly Connected Components form subtrees of the DFS tree.
       >> If we can find the head of such subtrees, we can print/store all the nodes in that subtree.
       >> There is no back edge from one SCC to another
    3. How to find all SCC heads in a given graph?
        Method 1 Tarjan Algorithm: O(V+E) DFS Tree
        Idea: SCC heads are U and V. ==> subSCC u -- U --- V -- v sub SCC
        Condition: low[u] == discovery[u]
        Note: low[v] indicates earliest visited vertex reachable from subtree rooted with v.
          
          3.1 DFS Tree
          3.2 Node U
            >> DFS tree rooted(U)
            >> if low[parent] == discovery[parent] then U is SCC head 
          
        4. Array
           discovery array: store the time when a node is visited
           low discovery time of a node low[v] = min(low[u], low[v])
           back edge: last edge through child to its original parent/head of SCC
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
        //G[e].push_back({s,w});
        
        Edges.push_back( {w, {s,e}} );
    }
    
    cout << "print_graph" << endl; 
    print_graph(G, V);
    
    print_SCC_heads(G, V);
    }
    return 0;
}