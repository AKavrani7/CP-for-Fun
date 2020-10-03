// https://leetcode.com/problems/cherry-pickup/

class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;
    
    bool isValid(int x, int y){
        return (x >=0 && y>=0 && x<n && y<m);
    }
    
    int util(vector<vector<int>>& A, int rf, int cf, int rb)
    {
        int cb = rf+cf-rb;
        if( !isValid(rf,cf) ||  !isValid(rb,cb) || A[rf][cf] == -1 || A[rb][cb] == -1)
            return INT_MIN;
        
        if(rf == n-1 && cf == m-1)
            return A[rf][cf];
        
        if(dp[rf][cf][rb] != -1)
            return dp[rf][cf][rb];
        
        int dd = util(A, rf+1, cf, rb+1);
        int dr = max(dd, util(A, rf+1, cf, rb));
        int rr = max(dr, util(A, rf, cf+1, rb));
        int rd = max(rr, util(A, rf, cf+1, rb+1));
        
        int ans = (rd + A[rf][cf]) + (rf != rb ? A[rb][cb] : 0);
        return dp[rf][cf][rb] = ans;
    }
    
    int cherryPickup(vector<vector<int>>& A) {
        
        n = A.size();
        m = A[0].size();
        if(A[0][0] == -1 || A[n-1][m-1] == -1)
            return 0;
        
        dp.resize(n, vector<vector<int>>(m, vector<int>(n,-1)));
        
        int ans = util(A, 0, 0, 0);
        return max(0, ans);
    }
};