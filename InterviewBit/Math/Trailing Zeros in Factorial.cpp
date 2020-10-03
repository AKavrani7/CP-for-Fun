int Solution::trailingZeroes(int A) {
    
    // https://www.interviewbit.com/problems/trailing-zeros-in-factorial/
    
    int ans = 0;
    
    if(A<=4) return ans;
    
    int i=5;
    while(A/i > 0)
    {
        ans += floor(A/i);
        i = i*5;
    }
       
    return ans;
}
