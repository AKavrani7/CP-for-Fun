vector<int> Solution::flip(string A) {
    
    
    // https://www.interviewbit.com/problems/flip/
    // variation of kadane algorithm
    // search for max sum countignous sub-array. (consider 0 as 1)
    
    
    vector<int> ans;
    int n = A.length();
    
    int count = 0;
    int max_flip = INT_MIN;
    int start = -1, end = -1;
    int start_tmp = 0;
    for(int i=0; i<n; i++)
    {
        if(A[i] == '1')
            count--;
        else
            count++;
        
        if(count < 0)
        {
            count = 0;
            start_tmp = i+1;
        }
        else if( max_flip < count)
        {
            max_flip = count;
            start = start_tmp;
            end = i;
        }
    }
    
    if(max_flip == INT_MIN)
        return ans;
    
    ans.push_back(start+1);
    ans.push_back(end+1);
    
    return ans;
}
