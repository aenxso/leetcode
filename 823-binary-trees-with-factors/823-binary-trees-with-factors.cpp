class Solution {
public:
    int mod = pow(10,9) + 7;
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(), A.end());
        unordered_map <int, long> rootWithCount;
        
        rootWithCount[A[0]] = 1;
        for(int i = 1; i < A.size(); i++) {
            long count = 1;
            for(auto j : rootWithCount) {
                int rootEle = j.first;
                if(A[i] % rootEle == 0 && rootWithCount.find(A[i] / rootEle) != rootWithCount.end()) {
                    count += rootWithCount[rootEle] * rootWithCount[A[i] / rootEle];
                    
                }
            }
            rootWithCount[A[i]] = count;
        }
        
        int numOfTrees = 0;
        for(auto i : rootWithCount) {
            numOfTrees = (numOfTrees + i.second) % mod;
        }
        
        return numOfTrees;
    }
};