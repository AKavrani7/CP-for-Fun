class Solution {
public:
    
    void merge(vector<int>& A, int s, int m, int e)
    {
        vector<int> tmp(e-s+1);
        int i=s, j=m+1,k=0;
        while(i<=m && j<=e)
        {
            if(A[i] >= A[j]) tmp[k++] = A[j++];
            else tmp[k++] = A[i++];
        }
        
        while(i<=m) tmp[k++] = A[i++];
        while(j<=e) tmp[k++] = A[j++];
        
        k=0;
        for(int i=s; i<=e; i++)
            A[i] = tmp[k++];
    }
    
    
    
    int merge_sort(vector<int>& A, int start, int end)
    {
        if(end < start) return 0;
        if(end == start) return 0;
        
        int mid = start + (end-start)/2;
        
        int l = merge_sort(A, start , mid);
        int r = merge_sort(A, mid+1, end);
        
        int ans = 0;
        
        int i=start,j=mid+1;
        while(j<=end && i<=mid)
        {
            long long ai = A[i];
            long long aj = A[j];
            aj = 2*aj;
            
            if(ai > aj)
            {
                ans += mid-i+1;
                j++;
            }
            else
                i++;
        }
        
        merge(A, start, mid, end);
        return ans+l+r;
        
    }
    
    int reversePairs(vector<int>& A) {
        
        // https://leetcode.com/problems/reverse-pairs/
        
        int ans = merge_sort(A, 0, A.size()-1);
        return ans;
    }
};