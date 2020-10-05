#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int sum(int n)
{
    if(n<=1) return n;
    int i=1;
    while(1)
    {
        if( (i*(i+1))/2 >= n) break;
        i++;
    }
    
    int row = i;
    long long ans = n;
    int l,r; 
    l = r = n;

    while(row--)
    {
        cout << l << " " << r << " " << ans << endl;
        l= max( (row*(row-1))/2+1, l-row-1);
        r= min( (row*(row+1))/2,   r-row); 
        
        int terms = r-l+1;
        ans = ans%mod + ((terms*(l+r))/2)%mod;
    }

    return ans%mod;
}

int main()
{	
  // https://imgur.com/gallery/kZ4p560
  // pyramid problem
  
  int n; cin >> n;
  
  int ans = sum(n);
  cout << ans << endl;
  return 0;
}