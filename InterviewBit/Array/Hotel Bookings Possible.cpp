bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    
    // https://www.interviewbit.com/problems/hotel-bookings-possible/
    // Idea: count the active no of guest in the hotel 
    // if some one arrive guest_count++
    // if some one depart guest_count--
    
    sort(arrive.begin(), arrive.end());
    sort(depart.begin(), depart.end());
    
    int n = arrive.size();
    int count = 0;
    int i=0;
    int j=0;
    
    while(i<n && j<n)
    {
        if(count > K)
            return false;
        
        if(arrive[i] < depart[j])
        {    
            i++;
            count++;
        }
        else
        {
            j++;
            count--;
        }
    }
    
    if(count > K)
        return false;
    
    return true;
}
