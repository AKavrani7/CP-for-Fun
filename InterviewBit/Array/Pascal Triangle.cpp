vector<vector<int> > Solution::solve(int n) {
    
    // https://www.interviewbit.com/problems/pascal-triangle/
    // Note: Traversal Structure 
    
    vector< vector<int> > ans(n);
    
    if(n==0)
        return ans;
        
    ans[0].push_back(1);
    
    for(int i=1; i<n; i++)
    {
        ans[i].push_back(1);
        
        for(int j=1; j<i; j++)
            ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]);
        
        ans[i].push_back(1);
    }
    
    return ans;
}
