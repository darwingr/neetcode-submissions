// Add all to max heap, queue removals in a max heap too
//  O(N log N)
//  O(N)
#include <ranges>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0 || k > nums.size())
            return {};
        
        vector<int> res;
        res.reserve(nums.size() - k + 1);

        priority_queue<int> max_heap;
        // init the window
        for (int n : nums | views::take(k-1))
            max_heap.push(n);
        priority_queue<int> removal_queue;
        
        for (int l = 0, r = k-1; r<nums.size(); l++, r++) {
            // handle new r
            max_heap.push(nums[r]);

            res.push_back(max_heap.top());

            // handle removing l
            removal_queue.push(nums[l]);
            // run removals
            while (!removal_queue.empty() && removal_queue.top() == max_heap.top()) {
                removal_queue.pop();
                max_heap.pop();
            }
        }
        return res;
    }
};
