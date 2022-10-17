class Solution {
public:
    bool checkIfPangram(string sentence) {
        // create an unordered set that contains every character in the given sentence
        // if every letter is present, the set size will be 26
        
        unordered_set<char> chars (sentence.begin(), sentence.end());
        return chars.size() == 26;
    }
};