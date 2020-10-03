int Solution::solve(vector<int> &A) {
    
    // https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/
    
    int n = A.size();
    int maxi = A[0];
    int mini = A[0];
    
    for(int i=1; i<n; i++)
    {
        if( A[i] > maxi)
            maxi = A[i];
        else if( A[i] < mini)
            mini = A[i];
    }
    
    return maxi + mini;
}
