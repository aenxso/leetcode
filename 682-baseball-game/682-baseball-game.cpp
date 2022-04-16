class Solution {
public:
    int calPoints(vector<string>& ops) {
        // use stack to keep track of the scores as ints
        
        stack<int> scores;
        int ans = 0;
        
        for(int i = 0; i < ops.size(); i++) {
            if(ops[i] == "C") {
                scores.pop();
            } else if(ops[i] == "D") {
                scores.push(scores.top() * 2);
            } else if(ops[i] == "+") {
                int tmp = scores.top();
                scores.pop();
                int sum = tmp + scores.top();
                scores.push(tmp);
                scores.push(sum);
            } else {
                scores.push(stoi(ops[i]));
            }
        }
        
        while(!scores.empty()) {
            ans += scores.top();
            scores.pop();
        }
        return ans;
    }
};