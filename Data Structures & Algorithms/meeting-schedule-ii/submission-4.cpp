// Line Sweep: ordered map of times to counts
//      ordered map: position/time to count
//      iterate the map, tracking count, best count
//  O(N log N)
//  O(N)
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> time_bookings;
        for (auto meeting : intervals) {
            time_bookings[meeting.start]++;
            time_bookings[meeting.end]--;
        }

        int max_rooms = 0;
        int rooms = 0;
        for (auto [_, bookings] : time_bookings) {
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