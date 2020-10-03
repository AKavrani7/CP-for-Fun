int Solution::solve(vector<int> &A, int B) {
    
    // https://www.interviewbit.com/problems/woodcutting-made-easy/
    
    int n = A.size();
    
    int min_h = 0;   // maximum wood 
    int max_h = 0;   // minimum wood
    
    for(int i=0; i<n; i++)
    {
        max_h = max(max_h, A[i]);
    }
    
    while(min_h <= max_h)
    {
        int mid = min_h + (max_h - min_h)/2;
        
        int total = 0;
        for(int i=0; i<n; i++)
        {
            total += max(0, A[i]-mid);
            
            if(total >= B)
                break;
        }
        
        if(total < B)
            max_h = mid-1;
        else
            min_h = mid+1;
    }
    
    return max_h;
}
