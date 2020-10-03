#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define bug(n) cout << n << "\n";

void solve()
{
    int N,M; cin >> N >> M;
    int ans = 0;
    
    queue<int> q;
    q.push(2);
    
    while(N-- && !q.empty())
    {
        int n = q.size();
        ans = (ans+n)%M;
        cout << n << " " << ans << endl;
        while(n--)
        {
            if(N == 0) break;
            
            int v = q.front();  q.pop();
            cout << v << " ";
            
            int no = (v*v+1)%M;
            for(int i=0; i<no; i++)
                q.push(i);
        }
        
        cout << endl;
    }
    
    bug(ans);
}

int main() {
	
	
	// https://imgur.com/a/DmOhAy4
	// https://ide.geeksforgeeks.org/N7k6cHultC
	
	int t = 1;
	while(t--)
	{
	    solve();
	}
	return 0;
}