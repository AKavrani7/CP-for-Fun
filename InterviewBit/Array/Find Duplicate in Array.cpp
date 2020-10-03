int Solution::repeatedNumber(const vector<int> &A) {
    
    // https://www.interviewbit.com/problems/find-duplicate-in-array/
    
    int n = A.size();
    
    bool check[n] = {false};
    
    
    for(int i=0; i<n; i++)
    {
        if( check[A[i]-1] )
            return A[i];
        
        check[A[i]-1] = true;
    }
    
    return -1;
}
