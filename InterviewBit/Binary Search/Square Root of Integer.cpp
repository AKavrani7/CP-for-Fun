int Solution::sqrt(int A) {
    
    // https://www.interviewbit.com/problems/square-root-of-integer/
    
    
    if(A == 0) return 0;
    if(A <= 3) return 1;
    
    long long end = A; 
    long long start = 1;
    long long mid;
    
    while(start < end)
    {
        mid = (start+end+1)/2; // valid for both odd and even no of terms in the scope
        
        if(mid*mid == A)
        {
            return mid;
        }
        else if(mid*mid > A)
            end = mid-1;
        else
            start = mid;
    }
    
    return start;
    
}
