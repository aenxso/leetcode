class Solution {
public:
    string longestPalindrome(string s) {
        // create a 2d array which is a truth table of sorts
        // rows represent starting pos, cols represent ending pos
        // for every index in the table (start/end point) write T/F if the corresponding string at start/end is a palindrome
        // if drawing table out, the middle diagonal will be all 1's because this represents all substrings which are length 1
        // ^ ie. comparing [1,1] [2,2] etc.
        // all subtrings of length 2 will be T if s[start] == s[end] (ie. "aa" "bb")
        // substrings of length >= 3 will utilize the table and values already entered in
        // substring of length 3+ is palin iff s[i] == s[j] && isPalin[i+1][j-1] (string inbetween is also palin)
        
        int n = s.length(), highestLen = 1, ansStart = 0;
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        
        // substrings of length 1
        for(int i = 0; i < n; i++) {
            isPalin[i][i] = true;
        }
        
        // substrings of length 2
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i + 1]) {
                isPalin[i][i + 1] = true;
                ansStart = i;
                highestLen = 2;
            }
        }
        
        
        // substrings of length 3+
        for(int k = 3; k <= n; k++) {            // k represents length of string, thus it starts at 3
            for(int i = 0; i < n - k + 1; i++) { // i = starting pos
                int j = i + k - 1;               // j = ending index. Calculate by adding length and starting pos -- needs to be updated every itr
                if(s[i] == s[j] && isPalin[i + 1][j - 1]) {
                    isPalin[i][j] = true;
                    if(k > highestLen) { // if length of longest palin string has increased
                        ansStart = i;    // update starting pos that will be used in returning answer
                        highestLen = k;
                    }
                }
            }
        }
        
        return s.substr(ansStart, highestLen);
    }
};