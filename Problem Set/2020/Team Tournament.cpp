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

int red, blue;

int find(int i, vector<int> parent)
{
    if(parent[i] == i)
        return i;
    
    return find(parent[i], parent);
}

bool check(int i, int color, vector<int> &parent)
{
    if(parent[i] == i)
    {
        parent[i] = color;
        return true;
    }
    
    if(color == red)
    {
        
        if(parent[parent[i]] == red) return false;
        else if(parent[parent[i]] == blue) return true;
        else if(!check(parent[i], blue, parent)) return false;
        parent[i] = red;
    }
    else
    {
        if(parent[parent[i]] == red) return true;
        else if(parent[parent[i]] == blue) return false;
        if(!check(parent[i], red, parent)) return false;
        parent[i] = blue;
    }
    
    return true;
}

int good_team(int n, int m, vector<pii> match)
{
    if(m<=1) return m;
    
    vector<int> parent(n+1);
    
    REP(i, 1, n)
        parent[i] = i;
    
    red = match[0].F;
    blue = match[0].S;
    
    REP(i, 1, m-1)
    {
        int l = match[i].F;  int r = match[i].S;
        int p_l = find(l, parent); int p_r = find(r, parent);
        
        bug(i);
        out(l); bug(p_l);
        out(r); bug(p_r);
           
        if(p_l == p_r) return i;
        else if( (p_l == red && p_r == blue) ||  (p_r == red && p_l == blue) )
            continue;
        else if(p_l == red)
        {
            cout << "p_l == red" << endl;
            if(!check(r, blue, parent)) return i; 
        }
        else if(p_l == blue)
        {
            cout << "p_l == blue" << endl;
            if(!check(r, red, parent)) return i; 
        }
        else
        {
            cout << "p_r = l" << endl;
            parent[r] = l;
            cout << parent[r] << " " << l << endl;
        }
    }
    
    return m;
}

void solve(){
    int n,m;
    cin >> n >> m;
    red = blue = -1;
    
    vector<pii> match(m);
    REP(i,0,m-1){
        cin >> match[i].F >> match[i].S;
    }
    
    int ans = good_team(n, m, match);
    bug(ans);
}

void prep(){
}

int main()
{
    // https://imgur.com/a/zD1spOF
    // https://ide.geeksforgeeks.org/gkplModS1W
    
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