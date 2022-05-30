class Solution {
public:
    int maxProduct(vector<string>& words) {
        // time: O(n * m), space: O(n), where n is length of words vector
        // idea is to use a bitset function which checks if there are any similar characters
        //   between the two strings
        
        int ans = 0;
        vector<bitset<26>> chars(words.size());
        for(int i = 0; i < words.size(); i++) {
            for(char &c : words[i]) {
                chars[i][c - 'a'] = 1;
            }
            for(int j = 0; j < i; j++) {
                if(!checkSame(chars[i], chars[j])) {
                    ans = max(ans, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return ans;
    }

private:
    bool checkSame(bitset<26>& a, bitset<26>& b) {
        for(int i = 0; i < 26; i++) {
            if(a[i] && b[i]) return true;
        }
        return false;
    }
};