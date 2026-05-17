// Sliding Window Maximum
//      2 max heaps: storing max so far & queueing removals
//  O(N log N)
//  O(N)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        res.reserve(nums.size() - k + 1);

        priority_queue<int> biggest;
        priority_queue<int> removal_queue;
        for (int l=0, r=0; r<nums.size(); l++, r++) {
            while(r-l+1 < k) {
                biggest.push(nums[r]);
                r++;
            }
            biggest.push(nums[r]);

            res.push_back(biggest.top());

            removal_queue.push(nums[l]);
            while (!removal_queue.empty() && removal_queue.top() == biggest.top()) {
                removal_queue.pop();
                biggest.pop();
            }
        }
        return res;
    }
};
