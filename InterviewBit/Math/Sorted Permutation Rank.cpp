#define MOD 1000003

int count_right(string str, int start, int end)
{
    int count = 0;
    
    for(int i=start +1; i<=end; i++)
        if(str[i] < str[start])
            count++;
    
    return count;
}

long long int factorial(long long int n)
{
    if(n <= 1)
        return 1;
        
    return (n*factorial(n-1))%MOD;
}

int Solution::findRank(string str) {
    
    // https://www.interviewbit.com/problems/sorted-permutation-rank/
    
    int ans = 0;
    int n = str.length();
    long long int factor;

    //cout << n << " " << factor << endl;
    for(int i = 0; i<n-1; i++)
    {
        factor = factorial(n-i-1);
        int no = count_right(str, i, n-1);
        ans += (no*factor)%MOD;
        ans = ans%MOD; 
        //cout << str[i] << " " << no << " " << ans << endl;
    }
    
    return (ans+1)%MOD;
}
