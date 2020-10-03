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

bool isPalindrome(string str, int n)
{
    int count[256] = {0};
    int sum = 0;
    REP(i,0,n-1)
        count[str[i]]++;
    
    
    int odd = 0;
    REP(i,0,127)
    {
        if(count[i]%2)
        {
            odd++;
            if(n%2 == 0) return false;
            if(n%2 && odd == 2) return false;
        }
        sum += count[i]%2;    
        sum %= 2;
    }
    
    //bug(sum);
    
    if(sum == n%2) 
        return true;
        
    return false;
}

void palindrome(string str)
{
    int n = str.length();
    
    //bug(str);
    if(!isPalindrome(str,n))
    {
        bug("Impossible");
        return;
    }
    
    int min_swap = 0;
    
    int left = 0, right = n-1;
    
    while(left < right)
    {
        if(str[left] == str[right])
        {
            left++; right--;
        }
        else
        {
            int l_it = left+1; 
            while(str[l_it] != str[right]) l_it++;
            int r_it = right-1;
            while(str[r_it] != str[left]) r_it--;
            
            if( l_it - left <= right - r_it)
            {
                min_swap += l_it - left;
                for(int i=l_it; i>left; i--)
                    str[i] = str[i-1];
                str[left] = str[right];
            }
            else
            {
                min_swap += right - r_it;
                for(int i=r_it; i<right; i++)
                    str[i] = str[i+1];
                str[right] = str[left];
            }
            
            left++; right--;
        }
    }
    
    //out("min_swap :"); out(min_swap); out(" final string: "); bug(str);
    bug(min_swap);
}


void solve(){
    
    string str;
    while(1)
    {
        cin >> str;
        if(str == "0")
            break;
            
        palindrome(str);
    }
}

void prep(){
}

int main()
{
    // https://www.codechef.com/problems/ENCD12
    // https://www.codechef.com/viewsolution/38183434
    
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