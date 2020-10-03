double Solution::findMedianSortedArrays(const vector<int> &a, const vector<int> &b) {

    // https://www.interviewbit.com/problems/median-of-array/
    // order should be small then large
    
    if(b.size()<a.size())
    {
        return findMedianSortedArrays(b,a);
    }
    
    int m = a.size(), n = b.size();
    // only one array
    if(m==0)
    {
        return n%2==0 ? 1.0*(b[n/2-1]+b[n/2])/2 : b[n/2];   
    }
    
    int st = 0;
    int en = m;
    int mid;
    
    int x = (n+m+1)/2; // required position of medium
    
    double median = 0;
    
    int LeftX, LeftY, RightX, RightY;
    int INF = 99999999;
    
    while(st<=en)
    {
        mid = (st+en)/2; 
        int k = x - mid; // shift = required - curr_mid(X)
        // shift + curr_mid(X) = (n+m+1)/2 median of two sorted arrays
        
        // X: .....Lx|Rx........ '|' ==> mid   
        // Y: .........Ly|Ry.... '|' ==> shift
        
        LeftX = (mid==0) ? -INF : a[mid-1];
        RightX = (mid==m) ? INF : a[mid];
        LeftY = (k==0) ? -INF : b[k-1];
        RightY = (k==0) ? INF : b[k];

        if(LeftX<=RightY && LeftY<=RightX)
        {
            median = (n+m)%2==0 ? 1.0*(max(LeftX, LeftY)+ min(RightX, RightY))/2 
                                        : max(LeftX, LeftY);
            
            //cout<<LeftX<<" "<<LeftY<<" "<<RightX<<" "<<RightY<<endl;
            
            return median;
            
        }
        else if(RightY>RightX) // smallest Ry to full fill the above condition
        {
            st = mid+1;
        }
        else                   // smallest Rx to full fill the above condition
        {
            en = mid-1;
        }
    }
    
    return median;
}