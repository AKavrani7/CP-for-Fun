vector<string> Solution::fizzBuzz(int A) {

    // https://www.interviewbit.com/problems/fizzbuzz/
        
    vector<string> arr(A);
    
    for(int i=0; i<A; i++)
    {
        if((i+1)%15 == 0)
            arr[i] = "FizzBuzz";
        else if((i+1)%5 == 0)
            arr[i] = "Buzz";
        else if((i+1)%3 == 0)
            arr[i] = "Fizz";
        else
            arr[i] = to_string(i+1);   
    }
    
    return arr;
}
