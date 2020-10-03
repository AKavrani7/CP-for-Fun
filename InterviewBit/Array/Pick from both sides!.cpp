int Solution::solve(vector<int> &A, int B) {
    
    // https://www.interviewbit.com/problems/pick-from-both-sides/
    
    int n = A.size();
    
    if(n == 0 || B == 0)
        return 0;
    int max_sum = INT_MIN;
    int wind_size = n - B;
    
    int S = 0, wS = 0;
    for(int i=0; i<wind_size; i++) wS += A[i];
    S = wS;
    for(int i=wind_size; i<n; i++) S += A[i];
    
    max_sum = S - wS;
    for(int i=wind_size; i<n; i++)
    {
        wS = wS + A[i] - A[i-wind_size];
        max_sum = max(max_sum, S - wS);
    }

    return max_sum;
}
