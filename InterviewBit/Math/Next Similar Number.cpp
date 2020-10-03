string Solution::solve(string A) {
    
    // https://www.interviewbit.com/problems/next-similar-number/
    // Note: Always Note the constraints length is 10^5. 
    
    int n = A.size();
    
    string ans = "";
    int count[10] = {0}; 
    
    count[A[n-1]-'0']++;
    
    bool flag = false;
    
    for(int i=n-2; i>=0; i--)
    {
        int no = A[i]-'0';
        for(int j=no+1; j<=9; j++)
        {
            if(count[j] == 0) continue;
            
            count[A[i]-'0']++;
            A[i] = j+'0';
            count[j]--;
            
            i++;
            for(int k=0; k<=9 && i<n; k++)
            {
                while(count[k]-- && i<n)
                    A[i++] = k+'0';
            }
            
            return A;
        }
        count[A[i]-'0']++;
        
    }
    
    return "-1";
}
