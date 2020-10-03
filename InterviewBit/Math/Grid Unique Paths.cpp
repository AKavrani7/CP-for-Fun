int Solution::uniquePaths(int A, int B) {
    
    // https://www.interviewbit.com/problems/grid-unique-paths/
    // math solution: MxN Grid total steps M+N-2 (M-1 rows, N-1 column)
    // so no of ways: (M+n-2)!/(M-1)!(N-1)!
    
    int dp[A][B];
    
    for(int i=0; i<A; i++)
        dp[i][0] = 1;
    for(int i=0; i<B; i++)
        dp[0][i] = 1;
    
    for(int i=1; i<A; i++)
        for(int j=1; j<B; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];

    return dp[A-1][B-1];
}
