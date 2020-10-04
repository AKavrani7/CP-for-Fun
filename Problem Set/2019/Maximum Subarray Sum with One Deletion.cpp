class Solution {
public:
    int maximumSum(vector<int>& A) {
        
        // https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
        
        int n = A.size();
        
        int incl = A[0];
        int excl = 0;
        int ans = A[0];
        
        for(int i=1; i<n; i++)
        {
            excl = max(incl, excl+A[i]);
            incl = max(incl + A[i], A[i]);
            ans = max({ans, incl, excl});
        }
        
        return ans;
    }
};