class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> stk;
        int score = 0;
        
        for(char c : s) {
            if(c == '(') {
                stk.push(score);
                score = 0;
            } else {
                score = stk.top() + max(score * 2, 1);
                stk.pop();
            }
        }
        
        return score;
    }
};