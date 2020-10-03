class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        
        // https://leetcode.com/problems/car-fleet/
        
        int n = pos.size();
        int ans = n;
        
        vector<pair<float,float>> car;
        for(int i=0; i<n; i++)
            car.push_back({pos[i], speed[i]});
        
        sort(car.begin(), car.end());
        
        // approach is similar to find next greatest element 
        
        stack<float> s;
        for(int i=0; i<n; i++)
        {
            float t = (1.0*(target-car[i].first))/(car[i].second*1.0);
            
            while(!s.empty() && s.top() <= t)
            {
                ans--;
                s.pop();
            }
            
            s.push(t);
        }
        
        
        return ans;
    }
};