class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // making a min-heap of absolute difference and corresponding array value
        // store the difference one by one with the array value
        // get the top of the heap i.e. the element with minimum absolute difference and pop k times
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans;
        
        for(int i = 0; i < arr.size(); i++) {
            pq.push({abs(arr[i] - x), arr[i]});
        }
        
        for(int i = 0; i < k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};