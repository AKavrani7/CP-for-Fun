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

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


    // https://www.interviewbit.com/problems/merge-intervals/
    // Checkout job scheduling

    if(newInterval.start > newInterval.end)
        swap(newInterval.start, newInterval.end);

    intervals.push_back(newInterval);
    
    sort(intervals.begin(), intervals.end(), mycompare);
    
    stack<Interval> s;
    s.push(intervals[0]);
    
    int n = intervals.size();
    
    for(int i=1; i<n; i++)
    {
        Interval itop = s.top();
        
        if(itop.end < intervals[i].start)
        {
            s.push(intervals[i]);
        }
        else if(itop.end >= intervals[i].end)
            continue;
        else if(itop.end < intervals[i].end)
        {
            s.pop();
            itop.end = intervals[i].end;
            s.push(itop);
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
