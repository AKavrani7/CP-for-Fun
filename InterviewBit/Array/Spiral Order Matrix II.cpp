vector<vector<int> > Solution::generateMatrix(int n) {
    
    // https://www.interviewbit.com/problems/spiral-order-matrix-ii/
    
    vector< vector<int> > ans(n, vector<int>(n,0) );
    int left = 0;
    int right = n-1;
    int top = 0;
    int bottom = n-1;
    
    int count = 1;
    int dir = 0;
    while(left <=right && top <= bottom)
    {
        if(dir == 0)
        {
            for(int i=left; i<=right; i++)
                ans[top][i] = count++;
            
            top++;
            dir = 1;
        }
        
        else if(dir == 1)
        {
            for(int i=top; i<=bottom; i++)
                ans[i][right] = count++;
            
            right--;
            dir = 2;
        }
        
        else if(dir == 2)
        {
            for(int i=right; i>=left; i--)
                ans[bottom][i] = count++;
            
            bottom--;
            dir = 3;
        }
        
        else if(dir == 3)
        {
            for(int i=bottom; i>=top; i--)
                ans[i][left] = count++;
            
            left++;
            dir = 0;
        }
    }
    
    return ans;
}
