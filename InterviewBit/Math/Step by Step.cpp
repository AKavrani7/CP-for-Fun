int Solution::solve(int A) {
    
    // https://www.interviewbit.com/problems/step-by-step/
    
    // 1 + 2 + ..... n = S
    // 1 + 2 - ..-.. n = A
    
    // condition  (S-A) >=0 && (S-A)%2 == 0. now find n?
    
    if(A == 0) return 0;
    
    A = abs(A);
    
    long long sum = 0;
    int ans = 0;
    
    int i = 1;
    while(1)
    {
        sum += i;
        ans++;
        
        if( (sum - A)%2 == 0 && (sum - A) >= 0)
            break;
        
        i++;
    }
    
    return ans;
}
