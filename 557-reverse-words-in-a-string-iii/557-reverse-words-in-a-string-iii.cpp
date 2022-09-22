class Solution {
public:
    string reverseWords(string s) {
        int l = 0, r = 0; // create two 'pointers' to keep track of position within string
        while(l < s.length()) {
            if(s[l] == ' ') {
                reverse(s.begin() + r, s.begin() + l);
                r = l + 1; // + 1 to skip space
            }
            l++;
        }
        reverse(s.begin() + r, s.end()); // reverse last word, gets skipped because of ' ' condition in loop
        return s;
    }
};