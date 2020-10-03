class Solution {
public:
    // https://imgur.com/a/qQBKbI4
    // https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/submissions/
    
    int find_sum(vector<int>& num, int d)
    {
        int n = num.size();
        int sum = 0;
        for(int i=0; i<n; i++)
        {
            sum += ceil((1.0*num[i])/d);
        }
        
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int thres) {
        int n = nums.size();
        int low = 1, high = nums[0];
        
        for(int i=1; i<n; i++)
            high = max(high, nums[i]); 
        
        while(low < high)
        {
            //cout << low << " " << high << endl;
            int mid = low + (high-low)/2;
            int sum = find_sum(nums, mid);
            //cout << mid << "--" << sum << endl;
            if(sum <= thres)
                high = mid;
            else
                low = mid+1;
        }
        //cout << low << " ans " << high << endl;
        
        return high;
    }
};