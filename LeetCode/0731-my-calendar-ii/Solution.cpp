class MyCalendarTwo {
public:
    vector<pair<int, int>> booked;
    vector<pair<int, int>> overlap;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        for(auto [s,e]:overlap){
            if(startTime<e && endTime>s){
                return false;
            }
        }
          // Record any new double-booked portions.
        for (auto [s, e] : booked) {
            if (startTime < e && endTime > s) {
                overlap.push_back({max(startTime, s), min(endTime, e)});
            }
        }

        booked.push_back({startTime, endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */