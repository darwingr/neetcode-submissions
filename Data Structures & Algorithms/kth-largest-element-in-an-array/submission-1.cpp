// min queue, max k elements
//  O(N log K)
//  O(K)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> bigs; // min heap
        for (int n : nums) {
            if (bigs.empty() || bigs.size() < k)
                bigs.push(n);
            else if (bigs.top() < n) {
                bigs.pop();
                bigs.push(n);
            }
        }
        return bigs.top();
    }
};
