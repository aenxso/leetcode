class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
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