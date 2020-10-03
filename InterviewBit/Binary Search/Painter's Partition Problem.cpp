#define mod 10000003
#define ll long long 

int Solution::paint(int A, int B, vector<int> &C) {
    
    // https://www.interviewbit.com/problems/painters-partition-problem/
    
    int n = C.size();
    int maxi_no = C[0];
    ll sum = C[0];
    
    for(int i=1; i<n; i++)
    {
        sum += C[i];
        maxi_no = max(maxi_no, C[i]);
    }
    
    ll low = maxi_no;
    ll high = sum;
    
    // A painter has to paint minimum (maximumlength of board) and maximum (all the board) 
        
    while(low < high)
    {
        ll mid = low + (high-low)/2; // let a painter has to paint mid units of board
        
        int no_of_painters = 1;
        ll total = 0;
        for(int i=0; i<n; i++)
        {
            total += C[i];
            
            if(total > mid)             
            {
                total = C[i];
                no_of_painters++;   // call another painter for rest pf the boards
                
                if(no_of_painters > A)
                    break;
            }
            
        }
        
        if(no_of_painters <= A)   // painter can paint less no of boards 
            high = mid;           // 3(mid) ==> 4(paint less than mid)
        else                      // we are out of painters give more work to them
            low = mid+1;          // 4(mid) ==> 3(paint more than mid)
    }   
    
    
    low = low%mod;              
    B = B%mod;
    return (mod + low*B)%mod;
}
