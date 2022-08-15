class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> values({
                                        {'I', 1},
                                        {'V', 5},
                                        {'X', 10},
                                        {'L', 50},
                                        {'C', 100},
                                        {'D', 500},
                                        {'M', 1000}
                                                   });
        int n = s.size();
        int num = values[s[n-1]];
        for(int i = n-2; i >= 0; i--) {
            if(values[s[i+1]] <= values[s[i]]) {
                num += values[s[i]];
            } else {
                num -= values[s[i]];
            }
        }
        return num;
    }
};