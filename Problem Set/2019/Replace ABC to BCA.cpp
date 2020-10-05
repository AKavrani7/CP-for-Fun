#include<bits/stdc++.h>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)

long long count(string s)
{
  int n = s.size();
  long long ans = 0;
  
  for(int i=0; i<n-2; i++)
  {
    if(s.substr(i, 3) != "ABC") continue;
   
    int l=i,r=i+2;
    while(l-1>=0 && s[l-1] == 'A') l--; // AABC ==> ABCA ==> BCAA
    while(r<n) 
    {	
       if(r+2<n && s.substr(r+1,2) == "BC") r += 2; // ABCBC ==> BCABC ==> BCBCA
       else if(r+1<n && s[r+1] == 'A') r += 1; // ABCABC ==> BCAABC ==> BCABCA ==> BCBCAA
       else break;
    }
    
    long long count = 0;
    for(int j=l; j<=r; j++) // (l)AA..(i)AB(i+2)C....AA...BC...A...BC/A(r)
    {
      if(s[j] == 'A') 
        count++; // no of A possible tranformation
      else if(j+1<n && s[j] == 'B' && s[j+1] == 'C') 
        ans += count; // BC fullfill the final transformation required
    }
    i=r;
  }
  
  return ans;
}

int main()
{
  // https://atcoder.jp/contests/agc034/tasks/agc034_b
  // https://atcoder.jp/contests/agc034/submissions/17203380
  io;
  string s; cin >> s;
  
  long long ans = count(s);
  cout << ans << endl;
  return 0;
}