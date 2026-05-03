// Sort then Stack bigger times to finish
#include <ranges>
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        cars.reserve(position.size());
        for (auto [pos, spd] : views::zip(position, speed))
            cars.push_back({pos, spd});
        ranges::sort(cars);

        stack<double> finish_times;
        for (auto [pos, spd] : cars | views::reverse) {
            int    dist_to_target = target - pos;
            double time_to_target = dist_to_target / static_cast<double>(spd);
            if (finish_times.empty() || time_to_target > finish_times.top())
                finish_times.push(time_to_target);
        }
        return finish_times.size();
    }
};
