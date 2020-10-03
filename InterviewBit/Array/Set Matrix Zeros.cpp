void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    // https://www.interviewbit.com/problems/set-matrix-zeros/
    
    int n = A.size();
    int m = A[0].size();
    
    bool r_flag = false;
    bool c_flag = false;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i == 0 && A[i][j] == 0)
                c_flag = true;
            
            if(j == 0 && A[i][j] == 0)
                r_flag = true;
            
            if(A[i][j] == 0)
            {
                A[0][j] = 0;
                A[i][0] = 0;
            }
        }
    }

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(A[i][0] == 0 || A[0][j] == 0)
                A[i][j] = 0;
        }
    }
    
    
    if(c_flag)
    {
        for(int j=0; j<m; j++)
            A[0][j] = 0;
    }
    
    if(r_flag)
    {
        for(int i=0; i<n; i++)
            A[i][0] = 0;
    }
    
}
