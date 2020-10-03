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
typedef pair<int, int> pi;
typedef map<int, int> mii;

///// General Purpose functions /////

/////////////////

int max_depth_nested_parenthesis(string str)
{
    int maxi = 0;
    int curr = 0;
    
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            curr++;
            maxi = max(maxi, curr);
        }
        else
        {
            curr--;
            if(curr < 0) return -1;
        }
    }
    
    if(curr != 0) return -1;
    
    return maxi;
}


void solve(){

   string str;
   cin >> str;
   
   // assuming order of parethesis are balanced if not use stack
   int ans = max_depth_nested_parenthesis(str);
   bug(ans);
}

void prep(){

}

int main()
{  
    // https://www.geeksforgeeks.org/find-maximum-depth-nested-parenthesis-string/
    // 
    
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