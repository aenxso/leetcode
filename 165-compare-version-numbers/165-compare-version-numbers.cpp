class Solution {
public:
    int compareVersion(string version1, string version2) {
        // traverse through both strings at the same time and compare their numerical values at each index
        // if one is found to be greater, return appropriate answer
        // if nothing is found by end of loop, reset num1 and num2 to compare next index value
        
        int num1 = 0, num2 = 0, i = 0, j = 0, n1 = version1.size(), n2 = version2.size();
        
        while(i < n1 || j < n2) {
            while(i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            while(j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            
            if(num1 < num2) {
                return -1;
            }
            if(num1 > num2) {
                return 1;
            }
            
            num1 = 0;
            num2 = 0;
            i++;
            j++;
        }
        return 0;
    }
};