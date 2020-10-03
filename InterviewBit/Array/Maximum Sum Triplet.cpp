int Solution::solve(vector<int> &A) {
    
    // https://www.interviewbit.com/problems/maximum-sum-triplet/
    // Learning: Right Max Array, Use of lower bound on set 
    
    
    int n = A.size();
    if(n<=2) return 0;
    
    int ans = 0;
    int right[n];
    right[n-1] = A[n-1];
    for(int i=n-2; i>=0; i--)
    {
        right[i] = max(right[i+1], A[i]);
    }
    
    set<int> s;
    s.insert(INT_MIN);
    s.insert(A[0]);
    
    for(int i=1; i<n-1; i++)
    {
        if(A[i] < right[i+1])
        {
            auto it = s.lower_bound(A[i]);
            it--;
            int lower_val = (*it);
            ans = max(ans, A[i] + lower_val + right[i+1]);
        }
        
        s.insert(A[i]);
    }
    
    return ans;
}
