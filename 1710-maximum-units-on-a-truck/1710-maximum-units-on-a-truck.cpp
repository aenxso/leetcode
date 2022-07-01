class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans = 0;
        sort(boxTypes.begin(), boxTypes.end(),[](vector<int> a, vector<int> b) {
           return a[1] > b[1]; 
        });
        
        for(auto box : boxTypes) {
            int limit = min(box[0], truckSize); 
            ans += limit * box[1];
            truckSize -= limit;
            if(!truckSize) break;
        }
        return ans;
    }
};