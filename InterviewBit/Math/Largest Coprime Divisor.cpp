int gcd(int a, int b)
{
    if(b == 0)
        return a;
    
    return gcd(b, a % b);
}

int Solution::cpFact(int A, int B) {

    // https://www.interviewbit.com/problems/largest-coprime-divisor/

    int gcd_ab = gcd(A, B);

    if(gcd_ab == 1)
        return A;
    
    return cpFact(A/gcd_ab, B);
    
}


