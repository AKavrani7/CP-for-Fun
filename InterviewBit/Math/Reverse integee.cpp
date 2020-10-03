int Solution::reverse(int A) {
    
    // https://www.interviewbit.com/problems/reverse-integer/
    
    bool neg = false;
    if(A < 0)
        neg = true;
    
    long ans = 0;
    A = abs(A);
    while(A)
    {
        ans = ans*10 + A%10;
        A = A/10;
        
        if(ans > INT_MAX || ans < INT_MIN)
            return 0;
    }
    
    
    if(ans > INT_MAX || ans < INT_MIN)
            return 0;
    
    if(neg)
        return -1*ans;
    
    return ans;
}
