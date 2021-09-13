class Solution {
public:
    int dayOfYear(string date) {
        //create vector with number of all days in a month in order
        //create string with last two chars in 'date', convert to int
        //add all month day values up to given month-1, then add on ^ date
        
        int ans = 0;
        vector<int> daysInMonths {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string day = date.substr(8, 2), month = date.substr(5, 2), year = date.substr(0, 4);
        int dayNum = stoi(day), monthNum = stoi(month), yearNum = stoi(year);
        for(int i = 0; i < monthNum - 1; i++) {
            ans += daysInMonths[i];
        }
        ans += dayNum;
        if (yearNum % 4 == 0 && yearNum % 100 != 0 && monthNum >= 3) { // check for leap year
            ans += 1;
        } else if (yearNum % 400 == 0 && monthNum >= 3) {
            ans += 1;
        } 
        return ans;
    }
};
