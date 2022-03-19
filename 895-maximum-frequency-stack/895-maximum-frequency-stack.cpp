class FreqStack {
public:
    FreqStack() {}
    
    void push(int val) {
        maxFreq = max(maxFreq, ++freq[val]);
        map[freq[val]].push(val);
    }
    
    int pop() {
        int val = map[maxFreq].top();
        map[maxFreq].pop();
        if(!map[freq[val]--].size()) maxFreq--;
        return val;
    }
    
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> map;
    int maxFreq = 0;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */