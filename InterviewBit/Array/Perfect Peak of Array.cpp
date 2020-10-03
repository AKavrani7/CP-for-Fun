int Solution::perfectPeak(vector<int> &A) {
    
    // https://www.interviewbit.com/problems/perfect-peak-of-array/
    // Ai > lmax && Ai < rmin ==> stricly increasing graph 
    
    int n = A.size();
    int lmax[n];
    int rmin[n];
    
    lmax[0] = A[0];
    rmin[n-1] = A[n-1];
    
    for(int i=1; i<n; i++) lmax[i] = max(A[i], lmax[i-1]);
    for(int i=n-2; i>=0; i--) rmin[i] = min(A[i], rmin[i+1]);
    
    for(int i=1; i<n-1; i++)
    {
        if(A[i] > lmax[i-1] && A[i] < rmin[i+1])
            return 1;
    }
    
    return 0;
}
