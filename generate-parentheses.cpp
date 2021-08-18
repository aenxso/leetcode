class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        builder(n, 0, 0, "", ans);
        return ans;
    }
    
    void builder(int n, int open, int close, string s, vector<string> &ans) {
        // base case
        if(close == n) {
            cout<<s<<endl;
            ans.push_back(s);
            return;
        }
        if(open < n) {
            builder(n, open + 1, close, s + '(', ans);
        }
        if(open > close) {
            builder(n, open, close + 1, s + ')', ans);
        }
    }
        
};

/*
NOTES:
 - http://ww1.sinaimg.cn/large/007KGHLngy1g6goqdf2h6j30jp0mp40g.jpg - image view of recursive call journey
 - when incrementing int in function call, DO NOT use '++' operator either before or after. Use good old 'x + 1'
 - adding char to string beforehand using '+=' operator DOES NOT WORK, neither does s = s + '('. Cannot add the element outside
    of the function call
 - DP programming way has 4 for loops apparently..
 
 
 // 1 -> "()"
 // 2 -> "(())" "() ()"
 // 3 -> "((()))","(()())","(())()","()(())","()()()"
*/
