class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int ans = 0;
        int n = s.size();
        for(int i = 1; i < n; i++) {
            if(s[i] == s[i - 1]) {
                ans += min(cost[i], cost[i - 1]); 
                cost[i] = max(cost[i], cost[i - 1]); 
            }     
        }
        
        return ans;
    }
};