// use DOUBLE for dist
#include <ranges>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, size_t>> mins; // max heap
        for (auto [i, p] : points | views::enumerate) {
            double dist = dist0(p[0], p[1]);
            pair<double, size_t> dist_idx = {dist, i};
            if (mins.empty() || mins.size() < k)
                mins.push(dist_idx);
            else if (mins.top() > dist_idx) {
                mins.pop();
                mins.push(dist_idx);
            }
        }

        vector<vector<int>> res;
        res.reserve(mins.size());
        while (!mins.empty()) {
            size_t i = mins.top().second;
            mins.pop();
            res.push_back(points[i]);
        }
        return res;
    }

    // sqrt((x1 - x2)^2 + (y1 - y2)^2)) from (0, 0)
    double dist0(int x, int y) {
        return sqrt(x*x + y*y);
    }
};
