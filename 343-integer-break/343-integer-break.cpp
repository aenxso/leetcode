class Solution {
public:
    int integerBreak(int n) {
        // create array storing max product for i at dp[i]
        
        if(n <= 2) return 1;
        
        vector<int> dp(n + 1, 0);
        dp[1] = 0;
        dp[2] = 1; // 2 = 1 + 1 so maxArr[2] = 1 * 1
        
        for(int i = 3; i <= n; i++) {
            for(int j = 0; j <= i/2; j++) {
                
                /** explanation from @adpa, 181024
                
                Try to write i as: i = j + x where x = i - j corresponds to either one number or a sum of two or more numbers
                
                Assuming that j + x corresponds to the optimal solution for maxArr[i], we have two cases:
                (1) i is the sum of two numbers, i.e. x = i - j is one number, and so maxArr[i] = j * (i - j)
                (2) i is the sum of at least three numbers, i.e. x = i - j is a sum of at least 2 numbers,
                and so the product of the numbers in this sum for x is maxArr[i - j]
                (=maximum product after breaking up i - j into a sum of at least two integers):
                maxArr[i] = j * maxArr[i - j]
                */
                
                dp[i] = max(dp[i], (max(j * (i - j), j * dp[i - j])));
            }
        }
        return dp[n];
    }
};