class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp; // used to store each occurence
        set<int> st;
        
        for(auto it : arr) {
            mp[it]++;
        }
        
        for(auto it : mp) {
            if(st.count(it.second)) return false; // if occurence for any value is already present 
                                                  // in the set then return false (not unique)
            st.insert(it.second);                    
        }
        
        return true;
    }
};