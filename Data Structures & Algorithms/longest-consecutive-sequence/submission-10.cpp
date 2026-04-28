class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> numToLen;
        int longest = 0;

        for (int num : nums) {
            if (numToLen[num])
                continue;

            // set current
            numToLen[num] = numToLen[num - 1] + 1 + numToLen[num + 1];

            // update the head
            int dist_to_head = num - numToLen[num - 1]; 
            numToLen[dist_to_head] = numToLen[num];

            // update the tail
            int dist_to_tail = num + numToLen[num + 1];
            numToLen[dist_to_tail] = numToLen[num];

            longest = max(longest, numToLen[num]);
        }
        return longest;
    }
};
