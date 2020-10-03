int Solution::maxSubArray(const vector<int> &A) {
    
    // https://www.interviewbit.com/problems/max-sum-contiguous-subarray/
        
    int max_sum = INT_MIN;

    int sum = 0;
    int i=0;
    int n = A.size();
    
    while(i<n)
    {
        sum += A[i];
        
        if(sum > max_sum)
            max_sum = sum;
        
        if(sum < 0)
            sum = 0;
            
        i++;
    }
    
    return max_sum;
}
