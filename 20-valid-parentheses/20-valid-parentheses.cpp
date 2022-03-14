class Solution {
public:
    bool isValid(string s) {
        // create a stack and push all opening brackets encountered onto the stack
        // if a closing bracket is found, check if the top of the stack is a match
        // if no return false, if yes then pop the stack and continue
        
        if(s.size() < 2) return false;
        stack<char> stk;
        
        for(char c : s) {
            switch(c) {
                case '(':
                    stk.push(c);
                    break;
                case '[':
                    stk.push(c);
                    break;
                case '{':
                    stk.push(c);
                    break;
                case ')':
                    if(!stk.empty() && stk.top() == '(') {
                        stk.pop();
                        break;
                    } else {
                        return false;
                    }
                case ']':
                    if(!stk.empty() && stk.top() == '[') {
                        stk.pop();
                        break;
                    } else {
                        return false;
                    }
                case '}':
                    if(!stk.empty() && stk.top() == '{') {
                        stk.pop();
                        break;
                    } else {
                        return false;
                    }
                default: ;
            }
        }
        return stk.empty();
    }
};