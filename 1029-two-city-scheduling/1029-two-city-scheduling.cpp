class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int minCost = 0, n = costs.size();
        vector<int> diffs;

        
        for(int i = 0; i < n; i++) {
            minCost += costs[i][0];
            diffs.push_back(costs[i][1] - costs[i][0]);
        }
        
        sort(diffs.begin(), diffs.end());
        
        for(int i = 0; i < n/2; i++) {
            minCost += diffs[i];
        }
        return minCost;
    }
};

        