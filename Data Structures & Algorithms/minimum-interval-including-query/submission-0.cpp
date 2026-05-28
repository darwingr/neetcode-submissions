// Sort both, iterate through them to match
//  O(NlogN + MlogM) - N intervals, M queries
//  O(N+M)
#include <ranges>
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<pair<int,int>> ints(intervals.size());
        for (int i=0; i<ints.size(); i++)
            ints[i] = {intervals[i].front(), intervals[i].back()};
        ranges::sort(ints);
        vector<pair<int, size_t>> sorted_queries;
        sorted_queries.reserve(queries.size());
        for (auto [idx, query] : queries | views::enumerate)
            sorted_queries.push_back({query, idx});
        ranges::sort(sorted_queries);

        using le = pair<int,int>; // len, end
        priority_queue<le, vector<le>, greater<le>> min_heap;
        vector<int> res(queries.size());
        size_t i = 0;
        for (auto [q, idx] : sorted_queries) {
            // expand options
            while (i<ints.size() && ints[i].first <= q) {
                auto [start, end] = ints[i];
                int len = end - start + 1;
                min_heap.push({len, end});
                i++;
            }

            // remove bad options
            while (!min_heap.empty() && min_heap.top().second < q)
                min_heap.pop();

            if (min_heap.empty())
                res[idx] = -1;
            else
                res[idx] = min_heap.top().first;
        }

        return res;
    }
};
