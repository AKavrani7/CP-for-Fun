vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    
    // https://www.interviewbit.com/problems/anti-diagonals/
    
    int n = A.size();
    vector< vector<int> > ans(2*n-1);
    
    for(int i=0; i<n; i++)
        for(int k=i,j=0; k>=0 && j<=i; k--, j++)
                ans[i].push_back(A[j][k]);
    
    for(int i=n-1; i>0; i--)
        for(int k=n-1, j=n-i;  k>=n-i && j<n; k--, j++)
            ans[n + n-i -1].push_back(A[j][k]);
    
    return ans;
}
