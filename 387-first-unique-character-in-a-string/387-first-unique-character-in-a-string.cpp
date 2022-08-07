class Solution {
public:
    int firstUniqChar(string s) {
        // create a char-pair map which stores the char, then a pair of its count and index
        // iterate through string once to fill map
        // iterate through map and keep track of the smallest index found with count == 1
        
        unordered_map<char, pair<int, int>> chars;
        int idx = s.size(); // set to s.size so we have a number to compare to in the return statement
        
        for(int i = 0; i < s.size(); i++) {
            chars[s[i]].first++; // increment the count
            chars[s[i]].second = i; // set the index
        }
        
        for(auto x : chars) {
            if(x.second.first == 1) {
                idx = min(idx, x.second.second);
            }
        }
        
        return idx == s.size() ? -1 : idx; // if idx is still set to s.size then there is no solution as it wasn't changed
    }
};