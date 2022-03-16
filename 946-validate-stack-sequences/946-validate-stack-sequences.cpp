class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // push every element from pushed onto a new stack
        // after pushing every element, check if it's the 'top' one in popped
        // if yes, pop the stack
        // check if the stack is empty at the end. If true it will be empty, false if not empty
        
        stack<int> stk;
        int i = 0;
        
        for(int x : pushed) {
            stk.push(x);
            while(!stk.empty() && stk.top() == popped[i]) {
                stk.pop();
                i++;
            }
        }
        return stk.empty();
    }
};