class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 1) {
            string best = s;
            for(int i = 0; i < s.size(); i++) {
                s = s.substr(1, s.size() - 1) + s[0];
                best = min(s, best);
            }
            return best;
        }
        sort(s.begin(), s.end());
        return s;
    }
};