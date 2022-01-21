class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size(), curGas = 0;
        
        // check if solution is possible
        for(int i = 0; i < n; i++) {
            curGas += gas[i] - cost[i];
        }
        if(curGas < 0) return -1; // no solution
        
        // find the starting point
        // since we have already confirmed that a solution is possible, there is no need
        // to wrap around once i passes n
        int start = 0;
        curGas = 0;
        for(int i = 0; i < n; i++) {
            curGas += gas[i] - cost[i];
            if(curGas < 0) {
                start = i + 1;
                curGas = 0;
            }
        }
        return start;
    }
};