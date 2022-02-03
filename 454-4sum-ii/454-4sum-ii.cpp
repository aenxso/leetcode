class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int ans = 0, n = nums1.size(); // all arrs are same size, so can use any for n
        unordered_map<int, int> sums; // map to store the first calculated value, to compare to second calculated value
        
        // get a value from first two arrays
        // increment value at location nums1[i] + nums2[j]
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                sums[nums1[i] + nums2[j]]++;
            }
        }
        
        // check if matching pair exists in next two arrays such that first sum + second sum == 0
        // if it exists, update ans
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans += sums[-(nums3[i] + nums4[j])]; // += value because duplicate tuples are also valid - count++ is not enough
            }
        }
        return ans;
    }
};