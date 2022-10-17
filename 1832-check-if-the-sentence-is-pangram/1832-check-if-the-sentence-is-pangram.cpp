class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> chars (sentence.begin(), sentence.end());
        return chars.size() == 26;
    }
};