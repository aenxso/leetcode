class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // map a character in the pattern to a word in the string, and map the string back onto the same character
        // loop through and make sure there is only one to one mapping for each char/word (bijection),
        // and that each char is mapped to at least one word
        
        int n = pattern.size(), i = 0;
        vector<int> pat(26, 0);
        unordered_map<string, int> map;
        istringstream ss (s);
        string word;
        
        for(string word; ss >> word; i++) {
            if(i == n || pat[pattern[i] - 'a'] != map[word]) { // if end is reached before all words in s are traversed
                                                               //   OR value of keys to words don't match
                return false;
            }
            pat[pattern[i] - 'a'] = i + 1; // otherwise map both to value i + 1
            map[word] = i + 1;             // 1-based indexing since map assigns 0 to keys not found (cr. @lllllll2)
        }
        
        return i == n;
    }
};