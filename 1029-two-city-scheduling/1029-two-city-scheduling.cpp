class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // first, calculate the total cost of sending everyone to city A
        // then store the cost difference between flying to city A and B for each person
        // sort the array carrying the differences, the biggest savings for flying to city B will be at the
        //   front of the diffs array
        // add n/2 of the first elements of sorted diffs to minCost
        
        int minCost = 0, n = costs.size();
        vector<int> diffs; // gives wrong answer if this is init'd as diffs(n)

        
        for(int i = 0; i < n; i++) {
            minCost += costs[i][0];                     // add up cost of everyone going to city A. eg 10 + 30 + 400 + 30 = 470
            diffs.push_back(costs[i][1] - costs[i][0]); // store diffs
        }
        
        sort(diffs.begin(), diffs.end());
        
        for(int i = 0; i < n/2; i++) {
            minCost += diffs[i];                        // add savings which will be a negative amount. eg. 470 + (-350) + -(10) = 110
        }
        return minCost;
    }
};

        