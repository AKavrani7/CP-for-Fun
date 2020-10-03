void Solution::rotate(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    // https://www.interviewbit.com/problems/rotate-matrix/
    
    int N = A.size();
    
    for(int i=0; i<N/2; i++)
    {
        for(int j=i; j<N-i-1; j++)
        {
            int tmp = A[i][j];
            A[i][j] = A[N-j-1][i];
            A[N-j-1][i] = A[N-i-1][N-j-1];
            A[N-i-1][N-j-1] = A[j][N-i-1];
            A[j][N-i-1] = tmp;
        }
    }
    
    return;
}
