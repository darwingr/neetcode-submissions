// Line sweep (queue)
//      time_bookings: map times to counts
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> time_bookings;
        for (auto [start, end] : intervals) {
            time_bookings[start]++;
            time_bookings[end]--;
        }

        int rooms = 0;
        int max_rooms = 0;
        for (auto [time, bookings] : time_bookings) {
            rooms += bookings;
            max_rooms = max(max_rooms, rooms);
        }
        return max_rooms;
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