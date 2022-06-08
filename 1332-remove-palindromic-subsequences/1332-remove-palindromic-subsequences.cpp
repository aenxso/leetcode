class Solution {
public:
    int removePalindromeSub(string s) {
        // one letter by itself is a palindrome
        // a SUBSEQUENCE doesn't have to be contiguous
        // therefore, since s only has two letters, the max number of steps to remove everything is 2
        // because all the a's can go in one step, and all the b's can go in the second step
        // if the string happens to be a palindrome anyway then the whole thing can go in one step
        
        int i = 0, j = s.size() - 1;
        
        while(i < j) {
            if(s[i] != s[j]) {
                return 2;
            }
            i++;
            j--;
        }
        return 1;
    }
};