string Solution::convertToTitle(int n) {
    
    // https://www.interviewbit.com/problems/excel-column-title/
    
    string str = "";
    while(n)
    {
        
        int no = n%26;
        if(no == 0)
        {
            no = 26;
            n = n-1;
        }
        
        
        char c = char(no - 1 + 'A');
        str = c + str;
        n = n/26;
        
        //cout << no << " " <<  n << " " << c << " " << str << endl;
    }
    
    return str;
}
