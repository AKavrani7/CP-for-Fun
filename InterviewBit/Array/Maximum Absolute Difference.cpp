#include <bits/stdc++.h>
int Solution::maxArr(vector<int> &A) {
    
    // https://www.interviewbit.com/problems/maximum-absolute-difference/
    // case 1: + + || - - 
    // f: |(A[i] + i) - (A[j] + j)| ==> max(A[i]+i) - min(A[i]+i)
    // case 2: - + || + - 
    // f: |(A[i] - i) - (A[j] - j)| ==> max(A[i]-i) - min(A[i]-i)
    
    int n = A.size();
    int ans = 0;
    int mini = INT_MAX;
    int maxi = INT_MIN;
    int count;
    
    for(int i=1; i<=n; i++)
    {
        count = A[i-1] - i;
        
        if(count > maxi)
            maxi = count;
        
        if(count < mini)
            mini = count;
    }
    
    ans = max(ans, maxi - mini);
    
    mini = INT_MAX;
    maxi = INT_MIN;
    for(int i=1; i<=n; i++)
    {
        count = A[i-1] + i;
        
        if(count > maxi)
            maxi = count;
        
        if(count < mini)
            mini = count;
    }
    
    ans = max(ans, maxi - mini);
    return ans;
}
