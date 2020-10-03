int Solution::isPower(int a) {
    
    // https://www.interviewbit.com/problems/power-of-two-integers/
    // N = A^P ==> P = log(N)/log(A) 
    
    if (a == 1) 
        return true; 
  
    for (int i = 2; i * i <= a; i++) { 
        double val = log(a) / log(i); 
        if ((val - (int)val) < 0.00000001) 
            return true; 
    } 
  
    return false; 
}
