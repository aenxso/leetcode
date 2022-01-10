class Solution {
public:
    int numDecodings(string s) {
        // bottom up processing
        // use array to store max ways of decoding strings of x length
        // therefore answer is the last value in the array
        
        int n = s.size();
        vector<int> dp(n + 1);  // array to store num of ways to decode string of length i or j or k etc.
                                // add one in case string is empty and need to return 0, or in case num of ways is OF length n
        dp[0] = 1; // num of ways to decode string of length 1
        dp[1] = s[0] == '0' ? 0 : 1; // nums of ways to decode string of length 1 depends on the character before it
       
        for(int i = 2; i <= n; i++) {
            int oneDigit = s[i - 1] - '0'; // need to use i-1 because string is 0 indexed, whereas array has an extra 1 space
            int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
            if(oneDigit >= 1) {
                dp[i] += dp[i - 1];
            }
            if(twoDigits >= 10 && twoDigits <= 26) {
                dp[i] += dp[i - 2];
            }
        }
        
        return dp[n];
    }
};