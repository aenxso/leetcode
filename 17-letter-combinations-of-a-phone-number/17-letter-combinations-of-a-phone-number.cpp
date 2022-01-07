class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;
        string comb = "";
        vector<string> map {
            {"0"}, {"1"}, {"abc"}, {"def"}, {"ghi"}, {"jkl"}, {"mno"}, {"pqrs"}, {"tuv"}, {"wxyz"}
        };
        
        backtrack(digits, ans, map, comb, 0);
        
        return ans;
    }

private:
    void backtrack(string& digits, vector<string>& ans, vector<string> map, string comb, int begin) {
        if(begin == digits.size()) { // base case
            ans.push_back(comb);
            return;
        }
        
        int number = digits[begin] - '0';
        for(int i = 0; i < map[number].size(); i++) {
            comb += map[number][i];
            backtrack(digits, ans, map, comb, begin + 1);
            comb.pop_back();
        }
    }
};