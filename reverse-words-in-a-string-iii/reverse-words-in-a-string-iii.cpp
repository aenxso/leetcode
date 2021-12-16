class Solution {
public:
    string reverseWords(string s) {
        int left = 0, right = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ') {
                right++;
            } else {
                reverse(s.begin() + left, s.begin() + right);
                left = right + 1;
                right++;
            }
        }
        reverse(s.begin() + left, s.end());
        return s;
    }
};