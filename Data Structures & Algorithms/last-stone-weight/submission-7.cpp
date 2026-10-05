#include <ranges>
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq; // size
        for (int s : stones)
            pq.push(s);

        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            x = abs(x - y);
            if (x > 0)
                pq.push(x);
        }
        if (pq.empty())
            return 0;
        return pq.top();
    }
};
