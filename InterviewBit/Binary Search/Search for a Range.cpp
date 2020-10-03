#define PB push_back

int binary_search_focc(const vector<int> &A, int B, int start, int end)
{
    int ans = -1;
    int mid;
    while(start <= end)
    {
        mid = start + (end-start)/2;
        if(A[mid] == B)
        {
            ans = mid;
            end = mid-1;
        }
        else if(A[mid] < B)
            start = mid+1;
        else
            end = mid-1;
    }
    
    return ans;
}

int binary_search_locc(const vector<int> &A, int B, int start, int end)
{
    int ans = -1;
    int mid;
    while(start <= end)
    {
        mid = start + (end-start)/2;
        if(A[mid] == B)
        {
            ans = mid;
            start = mid+1;
        }
        else if(A[mid] < B)
            start = mid+1;
        else
            end = mid-1;
    }
    
    return ans;
}

vector<int> Solution::searchRange(const vector<int> &A, int B) {
    
    // https://www.interviewbit.com/problems/search-for-a-range/
    
    vector<int> ans;
    int start = 0;
    int end = A.size()-1;
    
    int first_occ = binary_search_focc(A, B, 0, A.size()-1);
    int last_occ = binary_search_locc(A, B, 0, A.size()-1);
    
    ans.PB(first_occ);
    ans.PB(last_occ);
    
    return ans;
}
