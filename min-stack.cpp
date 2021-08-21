class MinStack {
    
private:
    stack<int> stk1; //for all items
    stack<int> stk2; //just for min elem
    
public:
    /** initialize your data structure here. */
//     MinStack() {
        
//     }
    
    void push(int val) {
        stk1.push(val);
        if(stk2.empty() || val <= getMin()) stk2.push(val); //if stk2 is empty, then val is the only elem and therefore has to be the min
    }
    
    void pop() {
        if(stk1.top() == getMin()) stk2.pop(); //if there is only 1 elem, both stks must be popped
        stk1.pop();
    }
    
    int top() {
        return stk1.top();
    }
    
    int getMin() {
        return stk2.top();
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
