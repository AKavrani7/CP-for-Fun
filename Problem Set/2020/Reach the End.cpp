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
#define bug(n) cout << n << "\n"; return
#define print(arr, start, end) REP(i, start, end) out(arr[i]); line

typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef map<int, int> mii;


/////////////
int n,m;
vector<pii> moves = {{0,1}, {1,0}, {0,-1}, {-1,0}};

bool util(vector<string> grid, int x, int y, int k, vector<vector<bool>> &visited)
{
    visited[x][y] = true;
    
    if(x == n-1 && y == m-1 && k>=0) return true;
    else if(k<=0) return false;
    
    for(int i=0; i<4; i++)
    {
        int cx = x + moves[i].F; int cy = y + moves[i].S;
        
        if(!(cx>=0 && cy>=0 && cx<n && cy<m && (grid[cx][cy] == '.'))) continue;
        
        if(!visited[cx][cy] && util(grid, cx, cy, k-1, visited)) return true;
    }
    
    return false;
}

void solve(){
   
   // https://imgur.com/a/qQBKbI4
   // 1. Reach the end
   // https://ide.geeksforgeeks.org/LCA9Uxj6D0
   
   cin >> n;
   vector<string> grid(n);
   REP(i,0,n-1) cin >> grid[i];
   int k; cin >> k;
   
   m = grid[0].size();
   if(grid[0][0] == '#' || grid[n-1][m-1] == '#') { bug("NO"); }
  
   vector<vector<bool>> visited(n, vector<bool>(m,false));
   bool ans = util(grid, 0, 0, k, visited);  
   
   if(ans) { bug("YES"); }
   bug("NO");
}   

void prep(){
}

int main()
{
	//code
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