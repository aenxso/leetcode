class MyCalendar {
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        // compare the maximum between the new start time and every enter event's start time with the minimum between
        //  the new event's end time and every entered event's end time
        // eg. [10,20], [15,25] -- the max start is 15, which is less than the min end which is 20. 15 < 20 therefore there is an overlap
        
        for(auto event : bookings) {
            if(max(event.first, start) < min(event.second, end)) return false;
        }
        bookings.push_back({start, end});
        
        return true;
    }
    
private:
    vector<pair<int, int>> bookings;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */