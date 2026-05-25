// Sort & iterate.
//  O(N Log N)
//  O(1)
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.empty() || intervals.size() == 1)
            return true;
        std::ranges::sort(intervals, [](auto a, auto b) { return a.start < b.start;});

        for (int i=1; i<intervals.size(); i++) {
            int prev_end = intervals[i-1].end;
            if (intervals[i].start < prev_end)
                return false;
        }
        return true;
    }
};

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */