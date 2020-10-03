bool mycompare(string a, string b)
{
    string ab =  a.append(b);
    string ba =  b.append(a);
    return ab.compare(ba) > 0 ? 1 : 0; 
}
 
string Solution::largestNumber(const vector<int> &A) {
    
    // https://www.interviewbit.com/problems/largest-number/
    
    int n = A.size();
    vector<string> ans(n);
    
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(A[i] == 0) count++;
        ans[i] = to_string(A[i]);
    }
    
    if(count == n)
        return "0";
    
    sort(ans.begin(), ans.end(), mycompare);
    
    string out = ans[0];
    for(int i=1; i<ans.size(); i++)
        out += ans[i];
    
    return out;
}
 