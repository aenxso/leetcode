class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<int> v = foundPattern(pattern);
        
        int n = words.size();
        vector<string> ans;
        
        for(int i = 0; i < n; i++) {
            vector<int> patternWord = foundPattern(words[i]);
            if(v == patternWord) {
                ans.push_back(words[i]);
            }
        }
        
        return ans;
    }
    
    vector<int> foundPattern(string pattern) {
        if(pattern.size() == 0) {
            return {};
        }

        vector<int> v;
        int ind = 0;

        unordered_map<char, int> mp;
        for(int i = 0; i < pattern.size(); i++) {
            if(mp.find(pattern[i]) == mp.end()) {
                mp.insert({pattern[i], ind++});
                v.push_back(mp[pattern[i]]);
            } else {
                v.push_back(mp[pattern[i]]);
            }
        }

        return v;
    }
};