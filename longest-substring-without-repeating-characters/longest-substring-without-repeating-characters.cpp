class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0) return 0;
        if(s.length() == 1) return 1;
        
        unordered_set<char> chars; // for logging all chars currently in longest substring
        int l = 0, r = 0, ans = 0, n = s.length();
        
        while(l < n && r < n) {
            if(chars.find(s[r]) == chars.end()) { // the current char is not yet in set
                chars.insert(s[r++]);
                ans = max(ans, (r - l));
            } else {
                chars.erase(s[l++]); // duplicate found - erase from set and make window smaller
                                     // if duplicate is in the middle of the substring, this step will repeat 
                                     // until the duplicate is reached and deleted - making window smaller everytime
            }
        }
        return ans;
    }
};