int Solution::gcd(int a, int b) {
    
    // https://www.interviewbit.com/problems/greatest-common-divisor/
    
    if(b == 0)
        return a;
        
    return gcd(b, a%b);
}
