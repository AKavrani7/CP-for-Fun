vector<int> Solution::findPerm(const string A, int B) {
    
    //https://www.interviewbit.com/problems/find-permutation/
    // string s has pattern: increasing or decreasing 
    // if increasing select the minimum number
    // if decreasing select the maximum number
    
    int start=1;
    int end=B;
    
    vector<int> ans;
    
    for(int i=0; A[i]; i++)
    {
        if(A[i] == 'I')
        {
            ans.push_back(start);
            start++;
        }
        else
        {
            ans.push_back(end);
            end--;
        }
    }
    
    ans.push_back(start);
    
    return ans;
}
