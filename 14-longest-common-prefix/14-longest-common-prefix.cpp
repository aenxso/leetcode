class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int index = 0;
        
        for(char c : strs[0]) {
            for(int i = 0; i < strs.size(); i++) {
                if(strs[i].size() < index || strs[i][index] != c) {
                    return ans;
                }
            }
            ans += c;
            index++;
        }
        return ans;
    }
};