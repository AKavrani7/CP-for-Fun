int Solution::findMin(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    
    // https://www.interviewbit.com/problems/rotated-array/
    // Binary Search on answer: pivot element has a property of local minima.
    
    
    // find the pivot element 
    int start = 0;
    int end = A.size()-1;
    int pivot = -1;
    int n = A.size();
    while(start <= end)
    {
        if(A[start] <= A[end])
        {
            pivot = start;
            break;
        }
        
        int mid = (start+end)/2;
        int next = (mid+1)%n;
        int prv  = (mid+n-1)%n;
        
        if(A[mid] <= A[next] && A[mid] <= A[prv])
        {
            pivot = mid;
            break;
        }
        else if(A[mid] >= A[start] && A[mid] >= A[end])
            start = mid+1;
        else
            end = mid-1;
    }
    
    return A[pivot];
}
