#define mod 1000000007
#define ll long long
 
void multiply(ll F[2][2], ll M[2][2])
{
    
    ll a = F[0][0]*M[0][0]%mod + F[0][1]*M[1][0]%mod;
    ll b = F[0][0]*M[0][1]%mod + F[0][1]*M[1][1]%mod;
    ll c = F[1][0]*M[0][0]%mod + F[1][1]*M[1][0]%mod;
    ll d = F[1][0]*M[0][1]%mod + F[1][1]*M[1][1]%mod;
    
    F[0][0] = a%mod;
    F[0][1] = b%mod;
    F[1][0] = c%mod;
    F[1][1] = d%mod;
}
 
void power(ll F[2][2], int n)
{
    if(n == 0 || n == 1)
        return ;
    
    power(F, n/2);
    multiply(F, F);
    
    if(n%2) 
    {
        ll M[2][2] = { {1,1} , {1,0} };
        multiply(F,M);
    }
}
 
 
int Solution::solve(int A) {
    
    if(A <= 0) return 0;
    
    ll F[2][2] = { {1,1} , {1,0} };
    power(F, A-1);
    
    return F[0][0]%mod;
}