class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // create array which stores whether (0,1) is ok to be segmented
        
        if(s.empty()) return false;
        vector<bool> dp(s.size() + 1, false); 
        dp[0] = true;
        
        for(int i = 1; i <= s.size(); i++) {
            for(int j = 0; j < i; j++) {
                if((dp[j]) && (find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end())) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};