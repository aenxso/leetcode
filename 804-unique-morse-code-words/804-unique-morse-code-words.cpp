class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse_code = {".-","-...","-.-.","-..",".","..-.","--.","....",
                                     "..",".---","-.-",".-..","--","-.","---",".--.",
                                     "--.-",".-.","...","-","..-","...-",".--","-..-",
                                     "-.--","--.."};
        unordered_set<string> codes;

        for(auto word : words) {
            string code = "";
            for(auto ch : word) {
                code += morse_code[ch - 'a'];
            }
            codes.insert(code);
        }

        return codes.size();
    }
};