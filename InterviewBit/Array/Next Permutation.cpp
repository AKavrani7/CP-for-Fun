vector<int> Solution::nextPermutation(vector<int> &A) {
    
    int n = A.size();
    
    // https://www.interviewbit.com/problems/next-permutation/
    // example: 1 2 3 1 ==> 3 > 2 or A[2] > A[1] then 1 3 2 1 sort(2 to end) ==> 1 3 1 2
    // example: 1 3 1 2 ==> 1 3 2 1 
    // example: 1 3 2 1 ==> 3 > 1 but is there any no greater then A[i-1] and less than A[i]
    // find j then swap then sort
    
    for(int i=n-1; i>0; i--)
    {
        if(A[i] > A[i-1])
        {
            int index = i;
            for(int j = i+1; j<n; j++)
                if(A[j] < A[index] && A[j] > A[i-1])
                    index = j;
            
            swap(A[index], A[i-1]);
            
            sort(A.begin() + i, A.end());
            return A;
        }
    }
    
    sort(A.begin(), A.end());
    return A;
}
