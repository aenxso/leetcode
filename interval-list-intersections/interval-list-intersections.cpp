class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        /*
            - taking [starti, endi] and [startj, endj], starti <= endj && startj <= endi. 
            - if these conditions are satisfied, intersection coordinates become [max(starti, startj), min(endi, endj)]
            - create two pointers, one for each list. After each itr, increment the list which has max(endi, endj)
        */
        
        if(firstList.size() == 0) return {};
        if(secondList.size() == 0) return {};
        vector<vector<int>> ans;
        int i = 0, j = 0;
        
        while(i < firstList.size() && j < secondList.size()) {
            if(firstList[i][0] <= secondList[j][1] && firstList[i][1] >= secondList[j][0]) {
                vector<int> intersect {max(firstList[i][0], secondList[j][0]), min(firstList[i][1], secondList[j][1])};
                ans.push_back(intersect);
            }
            if(firstList[i][1] == secondList[j][1]) {
                i++;
                j++;
            } else if(firstList[i][1] > secondList[j][1]) {
                j++;
            } else {
                i++;
            }
        }
        return ans;
    }
};