class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // keep track of the lowest price seen so far
        // subtract todays price with ^
        
        int ans = 0, lowest = INT_MAX;
        
        for(int i : prices) {
            lowest = min(lowest, i);
            int curr = i - lowest;
            ans = max(ans, curr);
        }
        
        return ans;
    }
};