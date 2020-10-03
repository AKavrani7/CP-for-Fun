int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    
    // https://www.interviewbit.com/problems/min-steps-in-infinite-grid/
    
    int ans = 0;
    int n = A.size();
    int count;
    
    for(int i=1; i<n; i++)
    {
        count = max( abs(A[i] - A[i-1]), abs(B[i] - B[i-1]) );
        ans += count;
    }
    
    return ans;
}
