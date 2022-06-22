class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // use max heap, pop off until we reach k (k - 1 for proper indexing)
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++) {
            pq.pop();
        }
        return pq.top();
    }
};