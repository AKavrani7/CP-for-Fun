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

int n;
vector<int> tshirts[101];
ll dp[1<<10][101];

void split_my_string(string s, int person)
{
    int i=0,no;
    string tmp = "";
    
    while(s[i])
    {
        if(s[i] == ' ')
        {
            no = stoi(tmp);
            tshirts[no].push_back(person);
            tmp = "";
        }
        else
            tmp += s[i];
        i++;
    }
    
    no = stoi(tmp);
    tshirts[no].push_back(person);
}


ll countWays(int tshirts_no, int mask)
{
    //cout << mask << " " << tshirts_no << " " << tshirts[tshirts_no].size() << endl;
    if(tshirts_no == 101)
    {
        if(mask == 0)
            return dp[mask][tshirts_no] = 1ll;
            
        return dp[mask][tshirts_no] = 0ll;
    }
    
    if(dp[mask][tshirts_no] != -1)
        return dp[mask][tshirts_no];

    ll ans = countWays(tshirts_no+1, mask)%MOD;

    for(int p=0; p<tshirts[tshirts_no].size(); p++)
    {
        int person = tshirts[tshirts_no][p];
        if(mask & (1<<person) )
        {
            int new_mask = (mask ^ (1<<person) );
            ans += countWays(tshirts_no+1, new_mask)%MOD;
            ans %= MOD;
            
            //cout << person << " <-person and mask-> " << new_mask << " ans: " << ans << endl;
        }
    }
    
    return dp[mask][tshirts_no] = ans;
}

void solve(){
   
   memset(dp, -1, sizeof(dp));
   for(int i=0; i<=100; i++)
        tshirts[i].clear();
        
   cin >> n;
   cin.ignore();
   for(int i=0; i<n; i++)
   {
       string s;
       getline(cin, s);
       split_my_string(s, i);
   }
   
   int mask = (1<<n)-1;
   //cout << n << " current mask: " << mask << endl; 
   int ans = countWays(1, mask)%MOD;
   
   cout << ans << endl;
}

void prep(){
}

int main()
{
    // https://www.codechef.com/problems/TSHIRTS
    
	//code
	io;
	int t = 1;
	cin >> t;
	prep();
	fix(12);
	while(t--){
	    solve();
	}
	
	return 0;
}