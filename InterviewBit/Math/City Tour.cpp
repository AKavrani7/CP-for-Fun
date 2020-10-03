#define ll long long
#define MOD 1000000007
#define PB push_back

ll powmod(ll base, ll expon)
{
    if(expon < 0)
        expon = MOD-1 + expon;
    
    ll ans = 1;
    base = base%MOD;
       
    while(expon)
    {
        if(expon & 1)
            ans = (ans*base)%MOD;
        
        base = (base*base)%MOD;
        expon = expon >> 1;
    }
    
    return ans%MOD;
}


int Solution::solve(int A, vector<int> &B) {
    
    // https://www.interviewbit.com/problems/city-tour/
    
    // sort visited cities
    sort(B.begin(), B.end());
    
    long long fact[1005];
    fact[0] = 1;
    for(int i=1; i<1005; i++)
        fact[i] = (i*fact[i-1])%MOD;
    
    // no of cities we have to visit = n-k (n cities, K visited)
    vector<ll> vs; 
    vs.PB(B[0]-1);
    int n = B.size();
    for(int i=1; i<n; i++)
        vs.PB(B[i] - B[i-1] - 1);
    vs.PB(A - B[n-1]);
    
    ll ans  = 1;
    ll deno = 1;
    ll sum = 0;
    
    for(int i=0; i<vs.size(); i++)
    {
        if(vs[i] == 0) continue;
        
        if(i != 0 &&  i != vs.size()-1)          // ............**.......
            ans = (ans*powmod(2, vs[i]-1))%MOD;  // ............*........ count 1    
                                                 // .............*....... count 1
        sum = (sum + vs[i])%MOD;
        deno = (deno*fact[vs[i]])%MOD;
    }
    
    ans = (ans*fact[sum])%MOD;
    ans = ( (ans%MOD)*(powmod(deno, MOD-2)%MOD) )%MOD;
    
    return ans;
}
