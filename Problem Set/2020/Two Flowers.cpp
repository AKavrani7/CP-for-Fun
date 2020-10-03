#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

#define MOD 1000000007
#define fix(n) cout << fixed << setprecision(n)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for(long i=a; i<=b; i++)
#define REN(i, a, b) for(long i=b; i>=a; i--)
// Debugging 
#define line cout << endl
#define out(n) cout << n << " "
#define bug(n) cout << n << "\n"
#define print(arr, start, end) REP(i, start, end) out(arr[i]); line

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef map<int, int> mii;

///// General Purpose functions /////

/////////////////
int n, m;
vector< pii > moves = {{-1,0}, {0,1}, {1,0}, {0,-1}};

bool isValid(int x, int y)
{
    if( x>=0 && y>=0 && x<n && y<m) return true;
    
    return false;
}

int find(int i, vector<int> &parent)
{
    if(parent[i] == i)
        return i;
    
    return find(parent[i], parent);
}


int cal_max_flower(vector<vector<int>> &grid)
{
	int ans = 0;
	vector<vector<int>> visited(n, vector<int>(m, -1));
	int node = -1;
	vector<int> node_count;
	vector<int> rank;
	
	REP(i,0,n-1) REP(j,0,m-1)
	{
	    if(visited[i][j] == -1)
	    {
	        visited[i][j] = ++node;
	        queue<pii> q;
	        q.push({i,j});
	        int count = 0;
	        
	        /// counting the similar type of node (consider as marking island with value node)
	        while(!q.empty())
	        {
	            pii tmp = q.front(); q.pop(); count++;
	            REP(x,0,3)
	            {
	                int cx = tmp.F + moves[x].F; int cy = tmp.S + moves[x].S;
	                if(isValid(cx, cy) && visited[cx][cy] == -1 && grid[cx][cy] == grid[i][j])
	                {
	                    visited[cx][cy] = node;
	                    q.push({cx,cy});   
	                }
	            }
	        }
	        
	        ans = max(ans, count);
	        rank.push_back(count);
	        node_count.push_back(count);
	        ///////////////////////////////////////////////
	    }
	}
	
	// Build Graph
	map<pii, vector<pii>> graph;
	REP(i,0,n-1) REP(j,0,m-1) REP(x, 0, 3)
	{
        int cx = i + moves[x].F; int cy = j + moves[x].S;
        if(isValid(cx, cy) && grid[cx][cy] <= grid[i][j])
            graph[ {grid[cx][cy],grid[i][j]} ].push_back( {visited[cx][cy], visited[i][j]} );
	}
	
	// disjoint set up 
	vector<int> parent(node+1);  
	REP(i,0,node) parent[i] = i;
	
	for(auto E : graph)
	{
	    vector<int> child;
	    for(auto e : E.S)
	    {
	        int left = e.F; int right = e.S; 
	        int pl = find(left, parent); int pr = find(right, parent);
	        
	        if(pl != pr)
	        {
	            if(rank[pl] < rank[pr]) swap(pl,pr);
	            parent[pr] = pl;
	            rank[pl] += rank[pr];
	            ans = max(ans, rank[pl]);
	        }
	        child.PB(left);
	        child.PB(right);
	    }
	    
	    for(auto c : child)
	    {
	        parent[c] = c;
	        rank[c] = node_count[c];
	    }
	}
	
	
	return ans;
}


void solve(){
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m));
    REP(i,0,n-1) REP(j,0,m-1) cin >> grid[i][j];
    
    // thought process: Hireachy wise
    // 1. Can you apply disjoint find union method
    // 2. if Yes, then procced only when it is complicated with bfs/dfs
    // 3. if No, backtracking or simple bfs/dfs problem
    
    int ans = cal_max_flower(grid);
    bug(ans);
}

void prep(){
}

int main()
{
    // Two Flower
    // https://www.codechef.com/problems/TWOFL
    // https://ide.geeksforgeeks.org/Kg2oZLa76v
    
	io;
	int t = 1;
	//cin >> t;
	prep();
	fix(12);
	while(t--){
	    solve();
	}
	
	return 0;
}