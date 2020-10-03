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

void fill_z(string str, vector<int> &z)
{
    int n = str.length();
    int L,R, k;
    
    z[0] = 0;
    L = R = 0;
    
    for(int i=1; i<n; i++)
    {
        if(i>R) 
        {
            //there does not exist a prefix-substring 
            //of S that starts before i and ends at or after i.
            
            L = R = i;
            while(R<n && str[R-L] == str[R])
                R++;
            z[i] = R-L;
            R--;
        }
        else
        {
            // pat$....L...i...R // L....R <= pat_length
            k = i-L;
            // z[i] >= min(z[k], R-i+1)
            if(z[k] < R-i+1) z[i] = z[k]; // L and R remains same 
            else
            {
                L=i;
                while(R<n && str[R-L] == str[R])
                    R++;
                z[i] = R-L;
                R--;
            }
        }
    }
}

int Z(string str, string pat)
{
    int count = 0;
    str = pat + "$" + str;
    int n = str.length();
    
    vector<int> z(n);
    fill_z(str, z);
    
    for(int i=0; i<n; i++)
    {
        if(z[i] == pat.length())
            count++;
    }
    
    return count;
}


void fill_lps(string pat, vector<int> &lps, int n)
{
    lps[0] = 0;
    int i=1, len = 0;
    while(i<n)
    {
        if(pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len == 0)  lps[i++] = 0;
            else len = lps[len-1];
        }
    }
}

int kmp(string str, string pat)
{
    int n = pat.length();
    int m = str.length();
    
    vector<int> lps(n);
    fill_lps(pat, lps, n);
    
    int count=0, i=0,j=0;
    while(i<m)
    {
        if(str[i] == pat[j])
        {
            i++;
            j++;
            
            if(j==n)
            {
                count++;
                j = lps[j-1];
            }
        }
        else
        {
            if(j==0) i++;
            else j = lps[j-1];
        }
    }
    
    return count;
}


/////////////////
void solve(){
    string pat,str;
    cin >> str >> pat;
    
    int ans_kmp = kmp(str, pat);
    int ans_z = Z(str, pat);
    
    out(ans_z); bug(ans_kmp);
}

void prep(){
}

int main()
{
    // https://ide.geeksforgeeks.org/mCTauXgkHe
    // https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
    // https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/?ref=rp
    // https://codeforces.com/blog/entry/3107
    
    
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