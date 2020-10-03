int Solution::titleToNumber(string str) {
    
    // https://www.interviewbit.com/problems/excel-column-number/
    
    int n = str.length();
    int ans = 0;
    int d = 1;
    
    //cout << str << endl;
    
    for(int i=0; i<n; i++)
    {
        ans += d*(str[n-i-1]-'A'+1);
        d = 26*d;
           
        //cout << i << " " << d << " " << ans << endl;
    }
    
    return ans;
}
