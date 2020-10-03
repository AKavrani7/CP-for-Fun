#include <bits/stdc++.h>

int Solution::solve(vector<string> &A) {
    
    // https://www.interviewbit.com/problems/triplets-with-sum-between-given-range/
    // a+b+c >= 2, change the maximum(a,b,c)
    // a+b+c <= 1, change the minimum(a,b,c)
    
    vector<float> seq;
    
    int n = A.size();
    float a, b, c;
    for(int i=0; i<n; i++)
    {
        a = stof(A[i]);
        
        if(a >= 2.0 )
            continue;
        
        seq.push_back(a);
    }
    
    n = seq.size();
    if(n<3)
        return 0;
    
    a = seq[0];
    b = seq[1];
    c = seq[2];
    
    for(int i=3; i<n; i++)
    {
        if(a+b+c > 1 && a+b+c < 2)
            return 1;
        
        float tmp = seq[i];
        
        // range 
        if(a + b + c >= 2)
        {
            if(a >= b && a >= c)
                a = tmp;
            else if(b >= a && b >= c)
                b = tmp;
            else
                c = tmp;
        }
        else 
        {
            if( a <= b && a <= c)
                a = tmp;
            else if( b <= a && b <= c)
                b = tmp;
            else
                c = tmp;
        }
        
    }
    
    if(a+b+c > 1 && a+b+c < 2)
            return 1;
    return 0;
}
