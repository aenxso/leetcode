class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 1) return {"()"};
        vector<string> ans;
        string combo;
        generate(n, n, ans, combo);
        return ans;
    }
    
private:
    void generate(int left, int right, vector<string>& ans, string combo) {
        if(left + right == 0) {
            ans.push_back(combo);
            return;
        }
        
        
        if(left > 0) {
            generate(left - 1, right, ans, combo + "(");
        }
        if(right > left) { // right needs to be bigger than left because there should not be more opening brackets than closing
            generate(left, right - 1, ans, combo + ")");
        }
        
        
        
    }
};