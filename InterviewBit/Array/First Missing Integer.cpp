int Solution::firstMissingPositive(vector<int> &A) {
    
    // https://www.interviewbit.com/problems/first-missing-integer/
    //  1 <= ans <= n+1
    //  set the index of element A[i] at i-1. 2(value) ==> 1(index)
    
    int n = A.size();
    int j=0;
    for(int i=0; i<n; i++)
    {
        if(A[i] > 0)
        {
            swap(A[i], A[j]);
            j++;
        }
    }
    
    if(j == 0)
        return 1;
    
    int siz = j;
    for(int i=0; i<siz; i++)
    {
        if( abs(A[i]) - 1 < siz && A[abs(A[i]) - 1] > 0)
            A[abs(A[i]) - 1] = -1*A[abs(A[i]) - 1];
    }
    
    for(int i=0; i<siz; i++)
    {
        if(A[i] > 0)
            return i+1;
    }
    
    return siz+1;
}
