class Solution {
public:
    string removeKdigits(string num, int k) {
        // go through every digit, and if the preceding value is higher, delete it from the string
        // use stack to keep track of the digits we are keeping
        
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
        
        // delete more values if k still isn't at 0
        while(k > 0) {
            k--;
            stack.pop_back();
        }
        
        // add stack chars (digits) to string
        // skip any preceding 0's
        for(char c : stack) {
            if(c == '0' && ans.empty()) continue;
            ans += c;
        }
        
        return ans.empty() ? "0" : ans;
    }
};