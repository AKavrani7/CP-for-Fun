int Solution::findCount(const vector<int> &A, int B) {
    
    // https://www.interviewbit.com/problems/count-element-occurence/
    
    int index = -1;
    int ans = 0;
    int start = 0;
    int end = A.size()-1;
    
    while(start <= end)
    {
        int mid = (start+end)/2;
        if(A[mid] == B)
        {
            index = mid;
            break;
        }
        else if(A[mid] < B)
            start = mid+1;
        else
            end = mid-1;
    }
    
    if(index == -1)
        return ans;
        
    ans++;
    start = index-1;
    end = index+1;
    
    // better apply binary search to find the start and end
    while(start >=0 && A[start] == B)
    {
        ans++;
        start--;
    }
    while(end <A.size() && A[end] == B)
    {
        ans++;
        end++;
    }
    
    return ans;
}
