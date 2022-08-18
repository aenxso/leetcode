class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int ans = 0, n1 = 0, n = arr.size();
        vector<int> v;
        unordered_map<int, int> map;
        
        for(int i = 0; i < n; i++) {
          map[arr[i]]++;
        }
    
        for(auto x : map) {
           v.push_back(x.second);
           
       }
        
        if(v.size() == 1) return 1;
        sort(v.begin(), v.end());
        
        for(int i = v.size() - 1; i >= 0; i--) {
            if(ans >= n / 2) {
              return n1;
            }
            n1++;
            ans = ans + v[i];
        }
        
        return 0;
    }
};