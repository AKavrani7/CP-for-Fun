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
void solve(){

    string str; cin >> str;
    long long answer = 0;
    
    map<int, int> m; // { value of a string, count of its existence in our string} 
    m[0] = 1;        // { empty string, 1 }
    int val = 0;      // { store the value of current contignous substring from start}
    
    for(auto c : str)
    {
        int d = c - 'A';  // Either Lower case or upper case. if(Lower and Upper then take long long val).  
        val = val ^ (1 << d);
        //out(d); out(val); out(m[val]); line; 
        
        answer += m[val];   // if it is repeated eg: ABAB(val = 0)
        //bug(answer);
        
        for (int i = 0; i < 26; ++i) 
        {
            //out(i);  
            //cout << (1 << i) << " " << (val ^ (1 << i)) << " ";
            //out(m[val ^ (1 << i)]); line;
            
            answer += m[val ^ (1 << i)]; 
            // {if the same value has occured before}
            // kind of similar to count the sum of subarray occured before or not
                                          
            //bug(answer);
        }
        
        m[val] += 1;
        
        // out(x); bug(m[val]);
    }
    
    bug(answer);
}

void prep(){

}

int main()
{
    // https://stackoverflow.com/questions/57515296/return-count-of-scatter-palindrome-of-a-string
    // https://ide.geeksforgeeks.org/ZIxa3h5meu
    
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