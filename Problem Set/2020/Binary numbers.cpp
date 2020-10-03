#include<bits/stdc++.h>
using namespace std;
#define bug(n) cout << n << endl

int fib[41];

string nth(int n)
{
    if(n == 1) return "1";
    
    /* n is toooo large
    queue<string> q;
    q.push("1");
    int count = 0;
    while(!q.empty())
    {
        string tmp = q.front(); q.pop();
        count++;
        if(count == n) return tmp;
        q.push(tmp + "0");
        if(tmp[tmp.size()-1] == '0') q.push(tmp + "1");
    } 
    return "-1";
    */

    string ans = "";
    int f = 0;
    
    for(int i=39; i>=0; i--)
    {
        if(fib[i] > n && f == 1)    // n = 7
            ans = ans + "0";       // n=2,i=2 len 3 to 2
                                  // n=0,i=0 len 1 to 0

        else if( n >= fib[i] )       // 7 >= fib[3],  2 >= fib[1]
        {
            f=1;                  // msb has occurred
            ans += "1";
            n = n-fib[i];         // length 4 to 3, n = 7-5=2
                                 // length 2 to 1, n = 2-2=0
        }
    }

    return ans; // 1001
}


void solve()
{
    int n; cin >> n;
    string ans = nth(n);
    bug(ans);
}

void prep()
{
    fib[0] = 1; 
    fib[1] = 2; // {0,1}
    fib[2] = 3; // {00, 01, 10}  
    fib[3] = 5; // {000, 001, 010, 100, 101}
    fib[4] = 8; // {0000, 0001, 0010, 0100, 0101, 1000, 1001, 1010}

    for(int i=5; i<=40; i++)
        fib[i] = fib[i-1] + fib[i-2];
}

int main()
{
    // https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/the-code-generator-9d3f9afa/description/
    
    int t;
    cin >> t;
    prep();
    while(t--)
    {
        solve();
    }

    return 0;
}