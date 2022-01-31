class Solution {
public:
    bool detectCapitalUse(string word) {
        if(isupper(word[0]) && isupper(word[1])) {
            for(int i = 2; i < word.length(); i++) { // checking all uppercase
                if(islower(word[i])) return false;
            }
        } else {
            for(int i = 1; i < word.length(); i++) {
                if(isupper(word[i])) return false;  // checking all lower OR only first letter is capital
            }
        }
        return true;
    }
};