class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> sFreq(26, 0);
        vector<int> tFreq(26, 0);
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        char ans;
        
        for(int i = 0; i < s.size(); i++) {
            sFreq[s[i] - 'a']++;
            // cout<<sFreq[i]<<endl;
        }
        cout<<sFreq.size()<<endl;
        for(int i = 0; i < t.size(); i++) {
            tFreq[t[i] - 'a']++;
            // cout<<tFreq[i]<<endl;
        }
        for(int i = 0; i < tFreq.size(); i++){
            cout<<sFreq[i]<<" vs. "<<tFreq[i]<<endl;
            if(sFreq[i] != tFreq[i]) {
                cout<<"found"<<endl;
                ans = alphabet[i % 26];
                break;
            }
        }
        return ans;
    }
};