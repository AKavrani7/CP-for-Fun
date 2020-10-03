vector<int> Solution::wave(vector<int> &A) {
    
    // https://www.interviewbit.com/problems/wave-array/
    
    sort(A.begin(), A.end());
    
    int n = A.size();
    
    for(int i=0; i<2*(n/2); i = i+2)
        swap(A[i], A[i+1]);
        
    return A;
}
