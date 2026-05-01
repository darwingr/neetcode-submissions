// 2-Pointer or sweep line (queue-based)
//      ordered map: position/time to count
//      iterate the map, tracking count, best count
//  O(N log N)
//  O(N)
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int,int> time_bookings;
        for (auto inter : intervals) {
            time_bookings[inter.start]++;
            time_bookings[inter.end]--;
        }

        int max_rooms = 0;
        int rooms = 0;
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