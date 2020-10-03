/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool mycompare(Interval a, Interval b)
{
    if(a.start == b.start)
        return a.end < b.end;
        
    return a.start < b.start;
}
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    sort(A.begin(), A.end(), mycompare);
    
    stack<Interval> s;
    s.push(A[0]);
    
    for(int i=1; i<A.size(); i++)
    {
        Interval tmp = s.top();
        
        if(tmp.end >= A[i].end)
            continue;
        else if(tmp.end < A[i].start)
            s.push(A[i]);
        else
        {
            s.pop();
            tmp.end = A[i].end;
            s.push(tmp);
        }
    }
    
    vector<Interval> ans;
    
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}