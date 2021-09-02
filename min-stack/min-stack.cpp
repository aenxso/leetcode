class MinStack {
private:
    // create one stack to hold normal vals, and one to hold the mins
    stack<int> s1;
    stack<int> s2;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int val) {
        s1.push(val);
        if(s2.empty() || s2.top() >= val) s2.push(val); // if s2.empty there is only one value so far and therefore must be the min
    }
    
    void pop() {
        if(s1.top() == s2.top()) s2.pop(); // check to delete from both stacks if necessary
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */