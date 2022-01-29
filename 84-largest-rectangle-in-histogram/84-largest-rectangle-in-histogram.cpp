class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // smallest heights[index] is the height cap
        // create empty stack, if stack is empty or heights[i] is higher than the bar at top of stack, then push i to stack
        // if this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater
        //   removed bar = heights[h]
        // for heights[h], the ‘left index’ is previous (previous to h) item in stack and ‘right index’ is i (current index)
        
        stack<int> indexes;
        int ans = 0, l, h; // h = top of stack, representing height
        
        int i = 0;
        while(i < heights.size()) {
            if(indexes.empty() || heights[indexes.top()] <= heights[i]) {
                indexes.push(i++);
            } else {
                h = indexes.top();
                indexes.pop();
                l = heights[h] * (indexes.empty() ? i : i - indexes.top() - 1); // calculate area with heights[h] as smallest
                if(ans < l) {
                    ans = l;
                }
            }
        }
        
        // pop remaining bars from stack and calculate area with every popped bar as the smallest
        while(!indexes.empty()) {
            h = indexes.top();
            indexes.pop();
            l = heights[h] * (indexes.empty() ? i : i - indexes.top() - 1);
            if(ans < l) {
                ans = l;
            }
            
        }
        return ans;
    }
};