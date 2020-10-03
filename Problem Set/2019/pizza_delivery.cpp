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


/////////////

void solve(){
    
    long double speed; cin >> speed;
    int n; cin >> n;
    vector<pii> coord(n);
    REP(i,0,n-1)
    {
        cin >> coord[i].F >> coord[i].S;
    }
    
    long double max_value = 0;
    
    REP(i,0,n-1)
    {
        REP(j,i+1, n-1)
        {
            long double val = sqrt(  1.0*(coord[i].F - coord[j].F)*(coord[i].F - coord[j].F) 
                                + 1.0*(coord[i].S - coord[j].S)*(coord[i].S - coord[j].S) );
            
            max_value = max(max_value, val);
            
            //cout << val << " " << max_value << " " << i << " " << j << endl;
        }
    }
    
    
    long double ans = max_value/(1.0*speed);
    
    ans = 3.666666666666;
    bug(ans);
    
    // 6 decimal places
    
    long double res = (long long)(ans*1000000 + 0.5);
    bug(res);
    res = (long double)(res + 0.0)/1000000;
    bug(res);
    
    bug("blah");
    long long t = ans*(1e7);
    if(t%10 >= 5) t = t/10 + 1;
    else t = t/10;
    bug(t);
    double out = ((double)(t+0.0)/1000000);
    bug(out);
}
void prep(){
}

int main()
{
    
    // https://ide.geeksforgeeks.org/Fhp5uyQTQX
    // https://imgur.com/a/DmOhAy4
    // https://imgur.com/a/ILQxzV9
    
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