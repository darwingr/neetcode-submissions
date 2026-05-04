// Sort by position then Stack greater arrival times than .top()
//  O(N log N)
//  O(N)
#include <ranges>
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        cars.reserve(position.size());
        for (auto [pos, spd] : views::zip(position, speed))
            cars.push_back({pos, spd});
        ranges::sort(cars);

        stack<double> arrival_times;
        for (auto [pos, spd] : cars | views::reverse) {
            int    dist_to_target = target - pos;
            double time_to_target = dist_to_target / static_cast<double>(spd);
            if (arrival_times.empty() || arrival_times.top() < time_to_target)
                arrival_times.push(time_to_target);
        }
        
        return arrival_times.size();
    }
};
