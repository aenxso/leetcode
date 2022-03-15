class Solution {
public:
    string minRemoveToMakeValid(string s) {
        // use two counters, one for open brackets and one for closing brackets
        // itereate through string and count all closing brackets
        // iterate through string again and match open brackets with remaining number of closing brackets available
        // if there is a match, append the brackets to answer string
        // if not, do not append and just adjust open/close counters
        // if a letter is encountered, add it to the answer string
        
        int open = 0, close = 0;
        string ans;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ')') close++;
        }
        
        for(char c : s) {
            if(c == '(') {
                open++;
                if(close > 0) { // decrease closing amount as an open bracket has matched it
                    close--;
                    ans += c;
                }
            } else if(c == ')') {
                if(open > 0) { // there is a matching closing bracket for this
                    open--;
                    ans += c;
                } else { // there is no closing bracket, and the remaining closing brackets can't be used for anything else
                    close--;
                }
            } else { // c is a letter
                ans += c;
            }
        }
        return ans;
    }
};