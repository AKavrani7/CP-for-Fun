#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007


int lsti(vector<int> A, int n)
{
    if(n<=2) return 0;
    
    sort(A.begin(), A.end());
    int ans = 0;
    
    for(int i=0; i<n-1; i++)
    {
        int lowest_sum = A[i] + A[i+1];
        int l = lower_bound(A.begin()+i+2, A.end(), lowest_sum) - (A.begin()+i+2);
        ans = max(l,ans);
        cout << i << endl;
        cout << l << " " << lowest_sum << " " << ans << endl;
    }
    
    return ans;   
}

int main()
{	
  // https://leetcode.com/discuss/interview-question/427394/siemens-sde-great-question-max-triangular-subsequence
  // longest subsequence satisfy triangular inequality
  // https://ide.geeksforgeeks.org/C4Hk5l3rFD
  
  int n; cin >> n;
  vector<int> v(n); for(int i=0; i<n; i++) cin >> v[i];
  
  int ans = lsti(v, n);
  cout << ans << endl;
  return 0;
}