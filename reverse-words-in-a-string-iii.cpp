class Solution {
public:
    string reverseWords(string s) {
        int l = 0; // create left 'pointer'
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                reverse(s.begin() + l, s.begin() + i);
                l = i + 1; // +1 to skip the space
            }  
        }
        reverse(s.begin() + l, s.end()); // reverse the last word (gets skipped because of ' ' condition)
        return s;
    }
};
