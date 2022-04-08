class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        index = k;
        for(int i : nums) {
            q.push(i);
            if(q.size() > index) q.pop();
        }
    }
    
    int add(int val) {
        q.push(val);
        if(q.size() > index) q.pop();
        return q.top();
    }
    
private:
    priority_queue<int, vector<int>, greater<int>> q;
    int index;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */