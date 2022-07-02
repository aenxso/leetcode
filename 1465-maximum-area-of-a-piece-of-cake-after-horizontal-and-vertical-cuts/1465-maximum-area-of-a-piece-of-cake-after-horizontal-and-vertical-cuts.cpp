class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {   
        hc.push_back(h);
        sort(hc.begin(), hc.end());
		int maxh = hc[0];
        for(int i = 1; i < hc.size(); i++){
            maxh = max(maxh, hc[i] - hc[i - 1]);
        }
        
        vc.push_back(w);
        sort(vc.begin(), vc.end());
		int maxv = vc[0];
        for(int i = 1; i < vc.size(); i++){
            maxv = max(maxv, vc[i] - vc[i - 1]);
        }
		
        return (1LL * maxh * maxv) % 1000000007; //1LL used to make the product long long or integer sign overflow will occur
    }
};