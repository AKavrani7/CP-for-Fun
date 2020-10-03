int findPivot(vector<int> &A)
{
    int n = A.size();
    int start = 0;
    int end = n-1;
    
    while(start <= end)
    {
        int mid = start + (end-start)/2;
        int next_index = (mid+1)%n;
        int prv_index = (n+mid-1)%n;
        
        if(A[mid] > A[prv_index] && A[mid] > A[next_index])
            return mid;
        else if(A[mid] < A[next_index])
            start = mid+1;
        else
            end = mid-1;
    }
    
    return -1;
}

int binary_search(vector<int> &A, int start, int end, bool inc, int B)
{
    //cout << inc << endl;
    
    if(inc)
    {
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            
            if(A[mid] == B)
                return mid;
                
            else if(A[mid] < B)
                start = mid+1;
            else
                end = mid-1;
        }
        
        return -1;
    }
    
    while(start <= end)
    {
        int mid = start + (end-start)/2;
            
        if(A[mid] == B) 
            return mid;
            
        else if(A[mid] < B)
            end = mid-1;
            
        else
            start = mid+1;
    }
        
    return -1;   
    
}


int Solution::solve(vector<int> &A, int B) {
    
    // https://www.interviewbit.com/problems/search-in-bitonic-array/
    
    int n = A.size();
    
    if(A[0] == B) return 0;
    if(A[n-1] == B) return n-1;

    int pivot = findPivot(A);
    
    //cout << pivot << endl;
    if(pivot == -1) return -1;
    if(A[pivot] == B) return pivot;
    
    
    int a = -1, b = -1;
    if(A[0] < B && A[pivot] > B)
        a = binary_search(A, 1, pivot-1, true, B);
    if(a != -1) return a;
    
    if(A[pivot] > B && A[n-1] < B)
        b = binary_search(A, pivot+1, n-2, false, B);
    if(b != -1) return b;
    
    return -1;
}
