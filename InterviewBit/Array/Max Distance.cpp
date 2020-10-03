int Solution::maximumGap(const vector<int> &A) {
    
    // https://www.interviewbit.com/problems/max-distance/
    // max(j-i) suct that A[j] >= A[i]
    // general kth term A[i] <= A[k] <= A[j]
     
    int n = A.size();
    if(n == 0)
        return -1;

    int left_min[n];
    int right_max[n];
    
    left_min[0] = A[0];
    for(int i=1; i<n; i++)
        left_min[i] = min(left_min[i-1], A[i]);
    
    right_max[n-1] = A[n-1];
    for(int i=n-2; i>=0; i--)
        right_max[i] = max(right_max[i+1], A[i]);
        
    int ans = 0;
    
    int i=0,j=0;
    
    while(i<n && j<n)
    {
        if(left_min[i] <= right_max[j])
        {
            ans = max( ans, j-i);
            j++;
        }
        else
            i++;
    }
    
    return ans;
}
