class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        recurs(s, ans, 0);
        return ans;
    }
    
private:
    void recurs(string& s, vector<string>& ans, int begin) {
        if(begin >= s.size()) {
            ans.push_back(s);
            return;
        }
        
        char c = s[begin]; // save state of char (upper/lowercase)
        s[begin] = islower(c) ? toupper(c) : tolower(c); // swap upper/lowercase
        recurs(s, ans, begin + 1); // run recursion
        if(isalpha(s[begin])) {
            s[begin] = c; // reset back to original and do recursion again
            recurs(s, ans, begin + 1);
        }
    }
};