class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        unordered_set<char> seen;
        
        int l = 0, r = 0, n = s.length(), ans = 0;
        while(l < n && r < n) {
            if(seen.find(s[r]) == seen.end()) {
                seen.insert(s[r++]);
                ans = max(ans, (r - l));
            } else {
                seen.erase(s[l++]);
            }
        }
        return ans;
    }
};