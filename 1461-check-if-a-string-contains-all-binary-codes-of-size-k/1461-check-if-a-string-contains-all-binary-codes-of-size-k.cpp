class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(k > s.size()) return false;
        
        unordered_set<string> substr_set;
        
        // insert each substring into unordered set
        for(int i = 0; i <= s.size() - k; i++) {
            substr_set.insert(s.substr(i, k));
        }
        
        // The number of distinct sub-strings should be exactly 2^k.
        return substr_set.size() == pow(2, k);
    }
};