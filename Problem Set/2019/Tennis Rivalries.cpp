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

int util(int n, int a, int b, int p)
{
    if(a < p*b) return 0;
    
    if(n == 0)
    {
        if(a >= p*b && a > b)
            return 1;
        else
            return 0;
    }
    
    int win = util(n-1, a+1, b, p);
    int loss = util(n-1, a, b+1, p);
    
    return win + loss;
}


void solve(){
   
   int n, p;
   cin >> n >> p;
   
   int ans = util(n, 0, 0, p);
   bug(ans);
   
   int dp[n][2];
   dp[0][0] = 0;
   dp[0][1] = 1;
   
   for(int i=1; i<n; i++)
   {
       if()
   }
}

void prep(){
}

int main()
{
	// https://imgur.com/a/QYD2bhJ 
	// tennis match

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