class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0, close = 0;
        string ans;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == ')') close++;
        }
        
        for(char c : s) {
            if(c == '(') {
                open++;
                if(close > 0) { // decrease closing amount as an open bracket has matched it
                    close--;
                    ans += c;
                }
            } else if(c == ')') {
                if(open > 0) { // there is a matching closing bracket for this
                    open--;
                    ans += c;
                } else { // there is no closing bracket, and the remaining closing brackets can't be used for anything else
                    close--;
                }
            } else { // c is a letter
                ans += c;
            }
        }
        return ans;
        
//         for(int i = 0; i < s.size(); i++) {
//             if(s[i] == '(') {
//                 // cout<<"open"<<endl;
//                 open++;
//             } else if(s[i] == ')') {
//                 // cout<<"close"<<endl;
//                 close++;
//                 if(open < close) {
//                     cout<<"open: "<<open<<", close: "<<close<<endl;
//                     s.erase(s.begin() + i);
//                     // cout<<"deleted"<<endl;
//                     close--;
//                     i--;
//                 }
//             } else { // if character is a letter
//                 continue;
//             }
//         }
        
//         if(open != close) {
//             cout<<"not equal"<<endl;
//             int diff = open - close;
//             for(int i = 0; i < s.size(); i++) {
//                 if(diff > 0 && s[i] == '(') {
//                     cout<<"deleted uneven"<<endl;
//                     s.erase(s.begin() + i);
//                     diff--;
//                     if(s.size() > 0) i--;
//                 } else {
//                     continue;
//                 }
//             }    
//         }
//         return s;
    }
};