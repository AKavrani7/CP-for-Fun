vector<int> Solution::getRow(int n) {
    
    // https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
    
    vector<int> ans;
    ans.push_back(1);
    
    if(n==0)
        return ans;
    
    vector<int> prv = Solution::getRow(n-1);
    
    for(int i=1; i<prv.size(); i++)
    {
        ans.push_back(prv[i]+prv[i-1]);
    }
    
    ans.push_back(1);
    
    return ans;
}
