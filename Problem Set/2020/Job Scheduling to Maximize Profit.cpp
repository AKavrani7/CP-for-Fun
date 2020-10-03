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
bool mycompare(vector<int> a, vector<int> b)
{
    if(a[1] == b[1])
        return a[0] < b[0];
    
    return a[1] < b[1];
}

void print2D(vector<vector<int>> M)
{
    int n = M.size()-1;
    int m = M[0].size()-1;
    REP(i,0,n)
    {
        REP(j,0,m)
            out(M[i][j]);
        line;
    }
}

int job_scheduling(vector<vector<int>> jobs)
{
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), mycompare);
    
    print2D(jobs);
    
    int dp[n];
    dp[0] = jobs[0][2];
    
    REP(i, 1, n-1)
    {
        int include = jobs[i][2];
        int l = 0, r = i-1;
        while(l <= r)
        {
            int mid = l + (r-l)/2;
            if(jobs[mid][1] <= jobs[i][0]) l = mid+1;
            else r = mid-1;
        }
        
        if(r != -1)
            include += dp[r];
        
        dp[i] = max(dp[i-1], include);
    }
    
    return dp[n-1];
}


void solve(){
    
    int n; cin >> n;
    vector<vector<int>> jobs(n,vector<int>(3));
    
    REP(i,0, n-1)
    {
        cin >> jobs[i][0]; // start
        cin >> jobs[i][1]; // finish
        cin >> jobs[i][2]; // profit
    }
    
    int max_profit = job_scheduling(jobs);
    bug(max_profit);
}

void prep(){

}

int main()
{
    // https://www.geeksforgeeks.org/weighted-job-scheduling/
    // https://binarysearch.com/problems/Job-Scheduling-to-Maximize-Profit
    // https://ide.geeksforgeeks.org/39T4v4fCtB
    
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