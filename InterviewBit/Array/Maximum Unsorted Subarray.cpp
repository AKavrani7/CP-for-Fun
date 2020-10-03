vector<int> Solution::subUnsort(vector<int> &A) {
    
    // https://www.interviewbit.com/problems/maximum-unsorted-subarray/
    // sort a subarray which will sort the entire array
    
    
    vector<int> ans;
    int n = A.size();
    
    int start = -1;
    for(int i=0; i<n-1; i++)
    {
        if(A[i] > A[i+1])
        {
            start = i;
            break;
        }
    }
    
    if(start == -1)
    {
        ans.push_back(-1);
        return ans;
    }
    
    int end = -1;
    for(int i=n-1; i>0; i--)
    {
        if(A[i] < A[i-1])
        {
            end = i;
            break;
        }
    }
    
    // so for sure from start to end A is unsorted
    
    int mini = start, maxi = start;
    for(int i=start+1; i<=end; i++)
    {
        if(A[i] < A[mini])
            mini = i;
        
        if(A[i] > A[maxi])
            maxi = i;
    }
    
    //index of mini and maxi of unsorted array
    
    
    // check from 0 to start -1
    
    //cout << start << " " << end << " " << mini << " " << maxi << " " << endl; 
    for(int i=0; i<start; i++)
    {
        if(A[i] > A[mini])
        {
            start = i;
            break;
        }
    }
    
    //cout << start << " " << end << " " << mini << " " << maxi << " " << endl;
    
    for(int i = n-1; i>=end+1; i--)
    {
        if(A[i] < A[maxi])
        {
            end = i;
            break;
        }
    }
    
    //cout << start << " " << end << " " << mini << " " << maxi << " " << endl;
    ans.push_back(start);
    ans.push_back(end);
    return ans;
}
