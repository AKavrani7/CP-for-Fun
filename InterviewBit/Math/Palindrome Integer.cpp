int Solution::isPalindrome(int n1) {
    
    // https://www.interviewbit.com/problems/palindrome-integer/
    
    if(n1 < 0)
        return 0;
    
    int a = n1;
    int n2 = 0;
    int power = 0;
    int no;
    
    while(a)
    {
        no = a%10;
        
        n2 = n2*10 + no;
        
        a = a/10;
        
        //cout << d << " " << power << " " << no << " " << n2 << " " << a << endl; 
    }
    
    return (n1==n2);
}
