int find_pivot(const vector<int> &A)
{
    int start = 0;
    int end = A.size()-1;
    
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        int next = (mid+1)%A.size();
        int prv = (mid-1 + A.size())%A.size();
        
        if(A[mid] < A[next] && A[mid] < A[prv])
            return mid;
        else if(A[mid] > A[start] && A[mid] > A[end])
            start = mid+1;
        else 
            end = mid-1;
    }
    
    return -1;
}

int binary_search(const vector<int> &A, int B, int start, int end)
{
    
    while(start <= end)
    {
        
        int mid = start + (end - start)/2;
        //cout << start << " " << end << " " << mid << " " << A[mid] << endl;
        if(A[mid] == B)
            return mid;
        else if(A[mid] < B)
            start = mid+1;
        else 
            end = mid-1;
        
    }
    
    return -1;
}

int Solution::search(const vector<int> &A, int B) {
    
    // https://www.interviewbit.com/problems/rotated-sorted-array-search/
    
    int n = A.size();
    int pivot = find_pivot(A);
    
    //cout << pivot << " " << A[pivot] << endl;
    
    if(A[pivot] <= B && A[n-1] >= B)
        return binary_search(A, B, pivot, n-1);
    
    //cout << "00" << endl;
    return binary_search(A, B, 0, pivot-1);
}
