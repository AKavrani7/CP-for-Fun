int Solution::solve(vector<int> &A) {
    
    // https://www.interviewbit.com/problems/noble-integer/
    
    sort(A.begin(), A.end());
    
    int n = A.size();
    for(int i=0; i<n; i++)
    {
        if(A[i] == A[i+1] && i<n-1)
            continue;
        
        if(A[i] == n-i-1 && A[i] >= 0)
            return 1;
    }
    
    return -1;
}

