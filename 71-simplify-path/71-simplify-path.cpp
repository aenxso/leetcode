class Solution {
public:
    string simplifyPath(string path) {
        // traverse string and use a stack to collect the valid bits of string which will be in the result string
        
        stack<string> stk;
        string ans = "";
        
        for(int i = 0; i < path.size(); i++) {
            if(path[i] == '/') continue;
            string tmp; // create a string of the proper elements which we will add to stack
            while(i < path.size() && path[i] != '/') { // additional '/' are ignored
                tmp += path[i];
                i++;
            }
            if(tmp == ".") {
                continue; // . is ignored in canonical so don't add to stk
            } else if(tmp == "..") {
                if(!stk.empty()) {
                    stk.pop(); // pop to reach the previous directory
                }
            } else {
                stk.push(tmp); // add string valid string bit to the stk
            }
        }
        
        while(!stk.empty()) {
            ans = '/' + stk.top() + ans;
            stk.pop();
        }
        return ans.size() == 0 ? "/" : ans;
    }
};