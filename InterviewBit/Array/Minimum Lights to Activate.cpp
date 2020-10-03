int Solution::solve(vector<int> &A, int B) {
    
    // https://www.interviewbit.com/problems/minimum-lights-to-activate/
    // check for each position  
    
    int n = A.size();
    int ans = 0;
    
    for(int i=0; i<n; i++)
    {
        bool flag = true;
        for(int j=min(n-1,i+B-1); j>=max(0,i-B+1); j--)
        {
            if(A[j] == 1)
            {
                flag = false;
                i = j+B-1;
                ans++;
                break;
            }
        }
        
        if(flag) return -1;
    }
    
    return ans;
}
