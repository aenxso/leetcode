class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return {};
        ans.push_back(""); // need to have an empty string first to add onto it
        unordered_map<int, string> values ({
                                                    {'2',"abc"},
                                                    {'3',"def"},
                                                    {'4',"ghi"},
                                                    {'5',"jkl"},
                                                    {'6',"mno"},
                                                    {'7',"pqrs"},
                                                    {'8',"tuv"},
                                                    {'9',"wxyz"}
                                                               });
        
        for(int i = 0; i < digits.length(); i++) {
            vector<string> tmp;
            // if(digits[i] < '2' && digits[i] > '9') continue; //error checking
            string next = values[digits[i]]; //get the required set of chars
            for(int j = 0; j < next.size(); j++) {
                for(int k = 0; k < ans.size(); k++) {
                    tmp.push_back(ans[k] + next[j]); //add each new character to what is already existing within the result;
                }
            }
            ans = tmp; //update the result
        }
        return ans;
    }
};
