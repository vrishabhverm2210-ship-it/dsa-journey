class MyCalendar {
public:
    vector<vector<int>> intervals;

    MyCalendar() {}

    bool book(int startTime, int endTime) {
        for (auto &interval : intervals) {
            int start1 = interval[0];
            int end1 = interval[1];

            // Check if the new booking overlaps
            if (startTime < end1 && endTime > start1) {
                return false;
            }
        }

        // No overlap, so accept the booking
        intervals.push_back({startTime, endTime});
        return true;
    }
};