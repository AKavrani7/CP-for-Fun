int Solution::books(vector<int> &A, int B) {
    
    // https://www.interviewbit.com/problems/allocate-books/
    // B students, minimum no of pages to study so that we can distribute load of books evenly
    
    int n = A.size();
    if(n < B)
        return -1;
    
    int low = A[0];
    int high = A[0];
    
    for(int i=1; i<n; i++)
    {
        low = max(low, A[i]);
        high += A[i];
    }
    
    // low ---------- high 
    // student can study a book of maximum pages or all the books 
    
    while(low < high)
    {
        int mid = low + (high-low)/2;  // each student has to study mid no of pages
        
        int no_of_students = 1;
        int total = 0;
        for(int i=0; i<n; i++)
        {
            if(A[i] > mid)             // Not Required
            {
                no_of_students = B+1;
                break;
            }
            
            total += A[i];          
            if(total > mid)           //  total no of students read at most mid pages    
            {                       
                no_of_students++;      
                total = A[i];
                
                if(no_of_students > B)  // total no > given no of students break
                    break;
            }
        }
        
        if(no_of_students <= B)      // one student can come and share the group's load
            high = mid;              // 3(mid) ==> 4(pages less than mid)
        else                         // group has to take load and read more pages
            low = mid+1;             // 4(mid) ==> 3(pages more than mid)
    }
    
    return low;
}
