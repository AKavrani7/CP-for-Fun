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
void solve(){
   
   int n; cin >> n;
   vi A(n); REP(i,0,n-1) cin >> A[i];
   int k; cin >> k;
   
   int low = 1, high = *max_element(A.begin(), A.end());
   
   while(low < high)
   {
       int mid = low + (high-low)/2, count = 0;
       
       cout << low << " " << mid << " " << high << endl;
       
       for(int i=0; i<n; i++)
       {
           if(A[i]%mid == 0) count += A[i]/mid-1;
           else count += A[i]/mid;
       }
       
       cout << mid <<  "--->" << count << endl;
       if(count <= k) high = mid;
       else low = mid+1;
   }
   
   cout << low << " ans "  << high << endl;
   
   bug(low);
   //bug("lol");
}

void prep(){
}

int main()
{
	//code: https://ide.geeksforgeeks.org/spyI4NZaM2
	// https://atcoder.jp/contests/abc174/tasks/abc174_e
	// P.S:
	/* Given an array arr containing positive elements and an integer K. 
	You have to perform K operations on the string. In one operation you can 
	pick an element of the’ array (suppose arr[i] ) into two parts p1,p2
	such that p1+p2=arr[i], Now you will delete arr[i] from the array 
	and insert p1   and p2. You need to find the minimum possible value 
	of the maximum element after performing the operation K times. */
	
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