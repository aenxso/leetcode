class Solution {
public:
    string frequencySort(string s) {
        string result = "";
        
        map<char, int> freq;
        for(char x : s) {
            if(freq.find(x) == freq.end()) {
                freq.insert(pair<char,int>(x,1));
            } else {
                freq[x]++;
            }
        }
        
        priority_queue<pair<int,char>> priorityQ;
        for(auto a : freq) {
            priorityQ.push({a.second, a.first});
        }
        
        while(!priorityQ.empty()) {
            int val = priorityQ.top().first;
            while(val > 0) {
                result += priorityQ.top().second;
                val--;
            }
            priorityQ.pop();
        }
        return result;
    }
};