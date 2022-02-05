class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, lowest = INT_MAX;
        
        for(int i = 0; i < prices.size(); i++) {
            lowest = min(prices[i], lowest);
            int curr = prices[i] - lowest;
            ans = max(ans, curr);
        }
        return ans;
    }
};