int Solution::solve(int A, vector<int> &B) {

    // https://www.interviewbit.com/problems/partitions/
    
    long long sum = 0;
    for(int i=0; i<A; i++)
        sum += B[i];
    if(sum%3 != 0)
        return 0;
    
    sum = sum/3;
    int ans =0;
    int count = 0;
    long long l_sum = sum;
    long long r_sum = 2*sum;
    sum = 0;
    
    for(int i=0; i<A; i++)  // concept: how many options are there for last r_sum: count
    {                           // sum sequemce '.'         >> ans, count
        sum += B[i];            // .......lsum.....rsum...... >> 1, 1
                                // .......lsum.....rsum......lsum >> 1, 2
        if(sum == r_sum)        // .......lsum.....rsum......lsum.... rsum >> 1+2, 2
            ans = ans + count;
        
        if(sum == l_sum)
            count++;
    }
    
    return ans;
}
