int Solution::pow(int a, int b, int c) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    // https://www.interviewbit.com/problems/implement-power-function/

    long long int ans = 1;
    long long int x = a;
    long long int n = b;
    long long int d = c;
    
    x = (d+x)%d;
    
    if(x == 0) return 0;
    
    while(n>0)
    {
        if(n & 1)
            ans = (d+(ans*x))%d;
        
        n = n>>1;
        x = (d+(x*x))%d;
    }
    
    return ans;
}
