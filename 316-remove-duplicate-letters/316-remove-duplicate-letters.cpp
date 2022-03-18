class Solution {
public:
    string removeDuplicateLetters(string s) {
        // create a stack to push letters onto, in smallest order ie. if 'd' is on stack and next is 'a', pop 'd' and add 'a'
        // create a vector to keep track of whether the current char has been seen yet or not
        // create a vector to keep track of the last known index of every letter that appears
        //   this way, we know whether or not we can pop a larger char off the stack - if it appears again
        //   later in the string, pop, if it doesn't appear again, don't pop
        
        stack<char> stk;
        vector<int> lastIndex(26, 0);
        vector<bool> seen(26, false);
        string ans = "";
        
        for(int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i; // farthest index for each letter will get overwritten if it appears multiple times
        }
        
        for(int i = 0; i < s.size(); i++) {
            int curChar = s[i] - 'a'; // get numerical value for current letter
            if(seen[curChar]) continue;  // already seen char, don't need to do anything
            while(!stk.empty() && stk.top() > s[i] && i < lastIndex[stk.top() - 'a']) {
                seen[stk.top() - 'a'] = false; // mark as unseen as we are deleting from stack
                stk.pop();
            }
            stk.push(s[i]);
            seen[curChar] = true;
        }
        
        while(!stk.empty()) { // add all letters on stack to answer string
            ans += stk.top();
            stk.pop();
        }
        
        reverse(ans.begin(), ans.end()); // answer will be backwards off stack so need to reverse it
        return ans;
        
    }
};