class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        // use a minheap and keep it at the size of k
        // this way the top will always be the kth largest, because we pop off the preceding values and can access
        // the kth largest element by using .top()
        // if we used a max heap, the maximums would be getting popped off and we need to keep those
        
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