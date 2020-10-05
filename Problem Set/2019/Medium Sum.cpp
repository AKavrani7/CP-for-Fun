#include<bits/stdc++.h>
using namespace std;

int main()
{	
  // https://atcoder.jp/contests/agc020/tasks/agc020_c
  // 
  int n; cin >> n;
  int S=0;
  vector<int> A(n);
  for(int i=0; i<n; i++) 
  { 
    cin >> A[i];  
    S += A[i]; 
  }
  
  if(n == 1)
  { 
    cout << A[0] << endl;
    return 0;
  }
  
  /* Logic: 
  1. Pi, Qi belongs to A
  2. Pi U Qi = A
  3. Pi intersection Qi = null
  example A = {1,2,1} P = {1}, Q = {2,1}
  let ΣPi and ΣQi be the sum of elements in Pi and Qi 
  let ΣPi ≤ ΣQi 
  ΣPi + ΣQi = ΣA
  ΣPi ≤ 0.5*ΣA and ΣQi ≥ 0.5*ΣA
  Assume that ΣPi belongs to the first half of S, which is S0, S1, . . . , S2N−1−1,
  while ΣQi belongs to the second half of S, which is S2N−1 , . . . , S2N −1.
  
  Set S: {0, 1, 2, 3, ...... 2^n-1} ==> index  
  Ans => index = 2^(n-1),  smallest value in Set S >= S/2.  
  */
  
  // Method 1 Time O(n*S/2)
  /*
  int sum = S;
  S = S/2;
  bool dp[n+1][S+1]; 
  for(int i=0; i<=n; i++) dp[i][0] = true;
  for(int j=1; j<=S; j++) dp[0][j] = false;
  
  for(int i=1; i<=n; i++)
  {
    for(int j=1; j<=S; j++)
    {
    	if(j>= A[i-1])
          dp[i][j] = dp[i-1][j] || dp[i-1][j-A[i-1]];
      	else
          dp[i][j] = dp[i-1][j];
    }
  }
  
  int ans = -1;
  for(int j=S; j>=1; j--)
    if(dp[n][j] == true)
    {ans = sum - j; break;}
  cout << ans << endl;
  */
  
  // Same Approach using bitset
  bitset<2000*2000+5> dp;
  dp[0] = 1;
  
  for(int i=0; i<n; i++)
  {
     dp = dp | (dp<<A[i]);  // set true for all the possible sum of subsets
  }
  
  S = (S+1)/2;
  while(dp[S] == 0)
    S++;
  cout << S << endl; 
  return 0;
}