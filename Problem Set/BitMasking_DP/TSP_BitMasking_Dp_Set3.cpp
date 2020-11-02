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
int dp[14][1<<14][101];

bool possible;
int min_distance(vector< pair<int, pii> > G[], int src, int mask, int E)
{
	if(mask == 0) 
	{ 
	    if(E>=0) { possible = true;  return 0; }
	    else return INT_MAX;
	}			
    
    if(E<=0) 
	    return INT_MAX;
    
	if(dp[src][mask][E] != -1)
		return dp[src][mask][E];

	int ans = INT_MAX;
	for(int i=0; i<G[src].size(); i++)
	{
		int child = G[src][i].F;	
		int dist = (G[src][i].S).F;
		int energy = (G[src][i].S).S;
        
        if(E<energy) continue;

		if( mask & (1<<child) )
		{
			int new_mask = mask ^ (1<<child);
			int val = min_distance(G, child, new_mask, E-energy);
			if(val != INT_MAX)
				ans = min(ans, dist + val);
		}
	}

	return dp[src][mask][E] = ans;
}

void solve(){
   
	int E;
	cin >> n >> m >> E;
	vector< pair<int, pii> > G[n];
	for(int i=0; i<m; i++)
	{
		int u,v,d,e;
		cin >> u >> v >> d >> e;
		G[u-1].push_back({v-1, {d,e}});
		G[v-1].push_back({u-1, {d,e}});
	}

	memset(dp, -1, sizeof(dp));
	possible = false;
	int mask = (1<<n)-1 -1; // 1st node visited
	int ans = min_distance(G, 0, mask, E);

	if(!possible) cout << -1 << endl;
	else cout << ans << endl;
}

void prep(){
}

int main()
{
    // Travelling salesman Problem
    // https://www.hackerearth.com/practice/algorithms/dynamic-programming/bit-masking/practice-problems/algorithm/fifth-1/description/
    // https://ide.geeksforgeeks.org/EWN6GKmY3t
    
    
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