vector<int> Solution::repeatedNumber(const vector<int> &A) {
    
    // https://www.interviewbit.com/problems/repeat-and-missing-number-array/
    // Another Method: set A[i] index to i-1. 2 ==> 1
    // or traverse the array find the no which points at an index twice 
    
    int n = A.size();
    int count[n+1] = {0};
    
    vector<int> ans;
    int a, b;
    a = b = -1;
    
    for(int i=0; i<n; i++)
        count[A[i]]++;
    
    for(int i=1; i<=n; i++)
    {
        if(a != -1 && b != -1) 
            break;
        
        if(count[i] == 2)
            a = i;
        
        if(count[i] == 0)
            b = i;
    }
    
    ans.push_back(a);
    ans.push_back(b);
    
    return ans;
}
