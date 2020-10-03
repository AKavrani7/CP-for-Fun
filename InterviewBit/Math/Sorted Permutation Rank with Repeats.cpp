// https://www.interviewbit.com/problems/sorted-permutation-rank-with-repeats/

#define lli long long int
lli md = 1e6+3;

lli factmod(lli n)
{
    lli ans=1;
    while(n>1)
    {
        ans=(ans%md * n%md)%md;
        n--;
    }
    return ans;
}

// The most important part
lli modexpo(lli a,lli n=md-2) //Fermat's Little theorem cuz md is prime
{
    if(n==0) return 1;
    if(n%2==0) return modexpo((a%md*a%md),n/2);
    else
    return (a%md * modexpo((a%md*a%md),(n-1)/2)%md)%md;
}

int Solution::findRank(string A) {
    
    //storing count for each of 256 characters in ASCII (just in case...)
    vector<int> cnt(256,0); 
    int n=A.length(); 
    
    //precomputing the cnt vector
    for(auto ch:A) 
        cnt[ch]++;
        
    lli ans=1;
    // denom is basically the denominator part 
    // where we divide for repeated characters (calculated using modular inverse only)
    lli denom=1; 
    
    //precomputing denominator with every repetition before the main loop
    for(auto ele:cnt)   
        denom=(denom%md*modexpo(factmod(ele))%md);
    
    for(int i=0;i<n;i++) //for each position (ith char) in the string
    {
        lli fact=factmod(n-i-1);
        //to store how many chars are less than ith char (repetition included)
        lli less_num=0; 
        for(int j=0; j!=A[i] ;j++) less_num+=cnt[j];
        
        // ((n-i-1)! * less_num)*(denom)
        ans = (ans%md + ((fact%md * (denom%md))%md * less_num%md)%md)%md; 
        
        //changing the denom for next iteration by multiplying the cnt of ith char
        denom = (denom%md * cnt[A[i]]%md)%md; 
        
        //and dec the cnt of ith character
        cnt[A[i]]--;  
    }
    return ans;
}