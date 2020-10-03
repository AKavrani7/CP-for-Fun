int Solution::findMedian(vector<vector<int> > &A) {
    
    // https://www.interviewbit.com/problems/matrix-median/
    // Median is the no greater than or equal to (n+1)/2 terms
    // odd length 1 2 3 ==> 2
    // even length 1 2 3 4 ==> (2+3)/2 = 2.5 
    
    int n = A.size();
    int m = A[0].size();
    
    int mid_count = (n*m + 1)/2;
    int mini = A[0][0];
    int maxi = A[0][m-1];
    
    for(int i=1; i<n; i++)
    {
        mini = min(mini, A[i][0]);
        maxi = max(maxi, A[i][m-1]);
    }
    
    while(mini < maxi)
    {
        int mid = (maxi + mini)/2;
        
        int count = 0;
        for(int i=0; i<n; i++)
            count += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        
        cout << mini << " " << mid << " " << maxi << endl;
        cout << count << " " << mid_count << endl;
        
        if(count >= mid_count)
            maxi = mid;
        else 
            mini = mid+1;
    }
    
    return maxi;
}
