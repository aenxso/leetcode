class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // brute = append all to nums1, then sort nums1
        // create extra 'pointer' to the back of nums1 - add values starting from here
        // create 2 more pointers - one for each array
        // nums1 pointer starts at nums1.end, nums2 pointer starts at nums2.end
        // at the end - while either not empty, append to nums1
        
        int i = m - 1, j = n - 1, k = m + n - 1; // end index of nums1, nums2, and extended end of nums1 respectively
        while(i >= 0 && j >= 0) {
            if(nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
        
        while(j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};