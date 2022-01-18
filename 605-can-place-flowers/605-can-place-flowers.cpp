class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int m) {
        int n = flowerbed.size(), zeroes = 1, ans = 0; // init zeroes at 1 to account for first element potentially being 0
        
        for(int i = 0; i < n; i++) { // count all the zeroes encountered
             if(flowerbed[i] == 0) { 
                 zeroes++;
             } else { // encountered a 1, reset zero count and adjust result
                 ans += (zeroes - 1) / 2;
                 zeroes = 0;
             }
        }
        
        if(zeroes > 0) { // if there are zeroes at the end of the array
            ans += zeroes / 2;
        }
        
        return ans >= m;
    }
};