class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        
        string prefix = "";
        int index = 0; //used as a checker to make sure we don't go out of bounds on shortest string
        
        for(char c : strs[0]) { //compare every char of every string starting at first char
            for(int i = 1; i < strs.size(); i++) {
                if(index >= strs[i].length() || c != strs[i][index]) { //if about to go out of bounds on shortest word, or chars are no longer equal
                    return prefix;
                }
            }
            prefix += c;
            index++;
        }
        return prefix;
    }
};
