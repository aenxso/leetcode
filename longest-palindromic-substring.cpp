class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 1) return s;
        int start = 0, maxLen = 1, n = s.length();
        vector<vector<bool>> table(n, vector<bool>(n, false));
        
        // fill table for 1-length substrings as all true
        for(int i = 0; i < n; i++) {
            table[i][i] = true;
        }
        
        // substrings of length 2
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i + 1]) {
                table[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }
        
        // substrings >= 3
        for(int k = 3; k <= n; k++) {
            for(int i = 0; i < n - k + 1; i++) {
                int j = i + k - 1; // get ending index
                if(table[i + 1][j - 1] && s[i] == s[j]) {
                    table[i][j] = true;
                    if(k > maxLen) {
                        start = i;
                        maxLen = k;
                    }
                }
                
            }
        }
        return s.substr(start, maxLen);
    }
};
