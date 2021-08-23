class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        int i = 0, j = 0, n = s.length(), result = 0;
        unordered_set<char> chars;
        
        while(i < n && j < n) {
            if(chars.find(s[j]) == chars.end()) {
                chars.insert(s[j++]);
                result = max(result, (j - i));
            } else {
                chars.erase(s[i++]);
            }
        }
        return result;
    }
};
