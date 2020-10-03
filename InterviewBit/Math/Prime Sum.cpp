vector<int> Solution::primesum(int n) {

    // https://www.interviewbit.com/problems/prime-sum/
    
    vector<int> ans;
    vector<bool> primes(n+1, true);
    primes[0] = false;
    primes[1] = false;
    
    for(int i=2; i<=n; i++)
    {
        if(primes[i])
        {
            for(int p=2; p*i<=n; p++)
            {
                primes[p*i] = false;
            }
        }
    }
    
    for(int i=2; i<n; i++)
    {
        if(primes[n-i] && primes[i])
        {
            ans.push_back(i);
            ans.push_back(n-i);
            
            break;
        }
    }
    
    return ans;
}
