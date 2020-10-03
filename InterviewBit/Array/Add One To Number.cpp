vector<int> Solution::plusOne(vector<int> &A) {
    
    // https://www.interviewbit.com/problems/add-one-to-number/
    
    vector<int> ans;
    int n = A.size();
    
    if( n == 1 && A[0] == 0)
    {
        ans.push_back(1);
        return ans;
    }
    
    int start = 0;
    while(start < n && A[start] == 0)
        start++;
    
    stack<int> s;
    int carry = 1;
    int sum;
    
    
    
    for(int i=n-1; i>=start; i--)
    {
        sum = carry + A[i];
        carry = sum/10;
        s.push(sum%10);
    }
    
    if(carry)
        s.push(carry);
        
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
}
