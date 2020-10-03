int Solution::solve(vector<int> &A, int B, int C) {
    
    // https://www.interviewbit.com/problems/numbers-of-length-n-and-value-less-than-k/
    
    int d = A.size();
    if(d==0)
        return 0;
    
    int k = 0;
    int n = B;
    vector<int> digit;
    
    int no = C;
    while(no)
    {
        k++;
        digit.insert(digit.begin(), no%10);
        no = no/10;
    }
    /*
    for(int i=0; i<k; i++)
        cout << digit[i] << " ";
    cout << endl;
    */
    // case1
    if(n>k)
        return 0;
    
    // case2
    if(n<k)
    {
        if(n == 1)
            return d;
            
        if(A[0] == 0)
            return (d-1)*pow(d,n-1);
        
        return pow(d,n);
    }
    
    // case3
    int dp[n+1];
    memset(dp, 0, sizeof(dp));
    
    int lower[11];
    memset(lower, 0, sizeof(lower));
    for(int i=0; i<d; i++)
        lower[A[i] + 1] = 1;
    for(int i=1; i<=10; i++)
        lower[i] += lower[i-1];
    /*
    for(int i=0; i<11; i++)
        cout << lower[i] << " ";
    cout << endl;
    */
    dp[0] = 0;
    bool flag = true;
    int d2 = 0;
    for(int i=1; i<=n; i++)
    {
        d2 = lower[digit[i-1]];
        dp[i] = dp[i-1]*d;
        
        if(i == 1 && n != 1 && A[0] == 0)
            d2 = d2-1;
            
        if(flag)
        {
            dp[i] += d2;
        }
        
        flag = flag & (lower[digit[i-1] +1] == lower[digit[i-1]] + 1);
        
        //cout << i << " " << dp[i] << " " << dp[i-1]*d << " " << d2 << endl; 
    }
    
    return dp[n];
}
