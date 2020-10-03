vector<int> Solution::solve(vector<int> &A) {
    
    // https://www.interviewbit.com/problems/leaders-in-an-array/
    
    int n = A.size();
    vector<int> ans;
    ans.push_back(A[n-1]);
    
    int rmax = A[n-1];
    
    for(int i=n-2; i>=0; i--)
    {
        if(A[i] > rmax)
        {
            ans.push_back(A[i]);
            rmax = A[i];
        }
    }
    
    return ans;
}
