class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);
        unordered_map<string,int> m;
        int c = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < words[i].size(); j++){
                string t = words[i].substr(0, j) + words[i].substr(j + 1);
                if(m.find(t) != m.end()){
                    m[words[i]] = max(m[words[i]], m[t] + 1);
                }else{
                    m[words[i]] = max(m[words[i]], 1);
                }
            }
            c = max(c, m[words[i]]);
        }
        return c;
    }
    
private:
    static bool comp(string &a, string &b){
        return (a.size() < b.size());
    }
};