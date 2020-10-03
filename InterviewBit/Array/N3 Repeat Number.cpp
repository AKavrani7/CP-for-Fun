int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    // interviewbit.com/problems/n3-repeat-number/
    // https://www.geeksforgeeks.org/majority-element/
    
    int count_1 = 0, count_2 = 0;
    int f, s;
    f = s = INT_MAX;
    
    int n = A.size();
    
    for(int i=0; i<n; i++)
    {
        if(f == A[i])
            count_1++;
        else if(s == A[i])
            count_2++;
        else if(count_1 == 0)
        {
            count_1++;
            f = A[i];
        }
        else if(count_2 == 0)
        {
            count_2++;
            s = A[i];
        }
        else
        {
            count_1--;
            count_2--;
        }
    }
    
    count_1 = 0;
    count_2 = 0;
    
    for(int i=0; i<n; i++)
    {
        if(f == A[i])
            count_1++;
        else if(s == A[i])
            count_2++;
        
        if(count_1 > n/3)
            return f;
        if(count_2 > n/3)
            return s;
    }
    
    return -1;
}
