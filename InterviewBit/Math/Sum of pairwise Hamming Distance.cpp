int Solution::hammingDistance(const vector<int> &A) {
    
    // https://www.interviewbit.com/problems/sum-of-pairwise-hamming-distance/
    
    int mod = 1000000007;
    long sum = 0;
    int n = A.size();
    
    for(int i=0; i<31; i++)
    {
        long sum_column_i = 0;
        for(int j=0; j<n; j++)
        {
            if(A[j] & (1 << i))
                sum_column_i++;
        }
        
        sum += (2*(sum_column_i%mod)*(n-sum_column_i%mod))%mod;
        sum = sum%mod;
        //cout  << i << " " << sum_column_i << " " << sum << endl;
    }
    
    int ans = sum%mod;
    return ans;
}
