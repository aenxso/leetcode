class Solution {
public:
    bool isValid(string s) {
        // create a stack and push all opening brackets encountered onto the stack
        // if a closing bracket is found, check if the top of the stack is a match
        // if no return false, if yes then pop the stack and continue
        
        if(s.length() < 2) return false;
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
                    if(stk.empty() || stk.top() != '(') { // make sure stk.empty check is first
                        return false;
                    } else {
                        stk.pop();
                        break;
                    }
                case ']':
                    if(stk.empty() || stk.top() != '[') {
                        return false;
                    } else {
                        stk.pop();
                        break;
                    }
                case '}':
                    if(stk.empty() || stk.top() != '{') {
                        return false;
                    } else {
                        stk.pop();
                        break;
                    }
                default: ;
            }
        }
        return stk.empty();
    }
};