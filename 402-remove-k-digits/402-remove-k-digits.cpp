class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.length()) return "0";
        
        string ans = "";
        vector<char> stack;
        
        for(int i = 0; i < num.length(); i++) {
            while((k > 0) && (!stack.empty()) && (stack.back() > num[i])) {
                stack.pop_back();
                k--;
            }
            stack.push_back(num[i]);
        }
        
        while(k > 0) {
            k--;
            stack.pop_back();
        }
        
        for(char c : stack) {
            if(c == '0' && ans.empty()) continue;
            ans += c;
        }
        
        return ans.empty() ? "0" : ans;
    }
};