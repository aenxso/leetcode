class Solution {
public:
    int scoreOfParentheses(string s) {
        // create a stack of ints
        // if open bracket, push the current score onto the stack then reset the score
        // if closing bracket, add the top of the stack to the score AND the max between 1 and 2*score
        // if sequence was (), encounter with the closing bracket will be 0 + max((0 * 2), 1)
        // if opening bracket is encountered after a closing bracket, the newly generated score gets
        //   saved on the stack and will be used for the remaining closing brackets (don't worry about
        //   the score getting deleted just because it resets to 0 on '(' encounters)
        
        stack<int> stk;
        int score = 0;
        
        for(char c : s) {
            if(c == '(') {
                stk.push(score); // latest score is stored on the stack, then score is reset
                score = 0;       // score is reset to 0 everytime an opening bracket is encountered
            } else {             // if closing bracket is encountered
                score = stk.top() + max(score * 2, 1);
                stk.pop();
            }
        }
        return score;
    }
};