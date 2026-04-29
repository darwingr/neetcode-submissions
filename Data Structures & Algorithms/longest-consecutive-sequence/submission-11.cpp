// Map val to len, update head & tails, track longest
//  O(N)
//  O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> numToLen;
        int longest = 0;
        for (int n : nums) {
            if (numToLen.contains(n))
                continue;

            int head_len = numToLen.contains(n-1) ? numToLen[n-1] : 0;
            int tail_len = numToLen.contains(n+1) ? numToLen[n+1] : 0;
            numToLen[n] = head_len + 1 + tail_len;

            if (numToLen.contains(n-1)) {
                int head_val = n - numToLen[n-1];
                numToLen[head_val] = numToLen[n];
            }

            if (numToLen.contains(n+1)) {
                int tail_val = n + numToLen[n+1];
                numToLen[tail_val] = numToLen[n];
            }

            longest = max(longest, numToLen[n]);
        }
        return longest;
    }
};
