class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // don't have to worry about selling in the past because that logic never gets coded
        
        int ans = 0, lowest = INT_MAX;
        
        for(int i = 0; i < prices.size(); i++) {
            lowest = min(prices[i], lowest); // keep track of lowest value found so far
            int curr = prices[i] - lowest;   // compute current profit that would be made if sold today
            ans = max(ans, curr);            // keep track of max profit seen so far
        }
        return ans;
    }
};