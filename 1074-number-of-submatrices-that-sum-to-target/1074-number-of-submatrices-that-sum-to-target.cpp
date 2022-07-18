class Solution {
public:
    int result = 0, target;
    unordered_map<int,int> map;
    
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        this->target = target;
        vector<int> row(matrix[0].size());
        for(int i = 0; i < matrix.size(); i++) {    // convert 2D array to 1D by row
            fill(row.begin(), row.end(), 0);        // clear vector to start the row with i as starting row
            for(int j = i; j < matrix.size(); j++) {
                for(int k = 0; k < matrix[0].size(); k++) { // add next row
                    row[k] += matrix[j][k];
                }
                getResult(row);
            }
        }
        return result;
    }
    
    void getResult(vector<int>& nums) { // get number of subarrays that sum to target
        int sum = 0;
        map.clear();
        map[0]++;
        for(int &i : nums) {
            sum += i;
            result += map[sum - target];   // get number of subarrays whose sum == target && end at i - add result to global result
            map[sum]++;                    // add the occurence of running sum to map
        }
    }
};