int Solution::solve(vector<int> &A) {
    
    // https://www.interviewbit.com/problems/balance-array/

    int n = A.size();
    int ans = 0;
    if(n <= 0) return 0;
    if(n == 1) return 1;
    
    int osum,esum;
    osum = esum = 0;
    
    for(int i=0; i<n; i++)
    {
        if(i%2) osum += A[i];
        else    esum += A[i];
    }
    
    int c_osum, c_esum, odd, even;
    c_osum = c_esum = 0;
    
    for(int i=0; i<n; i++)
    {
        if(i%2)
        {
            odd = c_osum + esum - c_esum;
            even = c_esum + osum - c_osum - A[i];
            
            if(odd == even) ans++;
            c_osum += A[i];
        }
        else
        {
            odd = c_osum + esum - c_esum - A[i];
            even = c_esum + osum - c_osum;
            
            if(even == odd) ans++;
            c_esum += A[i];
        }
    }
   
    return ans;
}