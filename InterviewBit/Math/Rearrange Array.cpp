void Solution::arrange(vector<int> &arr) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    // https://www.interviewbit.com/problems/rearrange-array/

    int n = arr.size();
    for(int i=0; i<n; i++)
    {
        arr[i] = arr[i] + (arr[arr[i]]%n)*n;
    }
    
    for(int i=0; i<n; i++)
    {
        arr[i] = arr[i]/n;
    }
}
