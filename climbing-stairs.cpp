class Solution {
public:
    int climbStairs(int n) {
        // base cases
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        
        vector<int> steps(n); // vector to store number of solutions per step
        steps[0] = 1; // okay to hardcode because they can never change - base cases
        steps[1] = 2;
        for(int i = 2; i < n; i++) {
            steps[i] = steps[i - 2] + steps[i - 1]; // beyond 2 steps, next step must be sum of previous two outcomes
        }
        return steps[n-1];
    }
};
