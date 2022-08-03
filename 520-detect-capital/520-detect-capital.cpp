class Solution {
public:
    bool detectCapitalUse(string word) {
        if(isupper(word[0]) && isupper(word[1])) { // check for word where ALL letters are capital
            for(int i = 2; i < word.length(); i++) {
                if(islower(word[i])) return false;
            }
        } else {
            for(int i = 1; i < word.length(); i++) { // checks for word where either first is upper or not, and all others are lower
                if(isupper(word[i])) return false;   // we don't have to explicitly check what the first letter is because it's either upper
                                                     //  or lower, and both are okay in the scenarios we are checking
            }
        }
        return true;
    }
};