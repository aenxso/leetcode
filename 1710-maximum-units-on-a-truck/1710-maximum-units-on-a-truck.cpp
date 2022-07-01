class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // sort and use greedy approach 
        
        int ans = 0;
        sort(boxTypes.begin(), boxTypes.end(),[](vector<int> a, vector<int> b) { // custom sort for second value in decreasing order
           return a[1] > b[1]; 
        });
        
        for(auto box : boxTypes) {
            int limit = min(box[0], truckSize); // choose numberOfBoxes which is smaller than the truck size
            ans += limit * box[1];              // increase ans by numOfBoxes * numOfUnits      
            truckSize -= limit;                 // decrease truck size so we don't go over
            if(!truckSize) break;               // capacity is full, exit loop
        }
        return ans;
    }
};