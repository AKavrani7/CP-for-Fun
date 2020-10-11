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

void solve()
{
    string s;
    cin >> s;
    
    int freq[26] = {0};
    int count_uc, count_lc, count_no, count_sc;
    count_uc = count_lc = count_no = count_sc = 0;
    
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            count_lc++; freq[s[i]- 'a']++;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z')
            count_uc++;
        else if(s[i] >= '0' && s[i] <= '9')
            count_no++;
        else
            count_sc++;
    }
    
    char c; int maxi = 0;
    for(int i=0; i<26; i++)
    {
        if(freq[i] > maxi) { 
            maxi = freq[i];
            c = 'a'+i;
        }
    }
    
    
    //bug(count_uc); 
    //out(count_lc); 
    bug(c);
    //bug(count_no);
    //bug(count_sc);
    
}

void prep(){

}

int main()
{	
	// https://practice.geeksforgeeks.org/problems/count-type-of-characters/0
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