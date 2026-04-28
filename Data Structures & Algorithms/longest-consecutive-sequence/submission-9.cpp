class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> numToStartIndex;
        for (int i=0; i<nums.size(); i++) {
            int num = nums[i];

            // seen?
            if (numToStartIndex.contains(num))
                continue;
            // starting or tailing?
            if (numToStartIndex.contains(num-1))
                numToStartIndex[num] = numToStartIndex[num - 1];
            else
                numToStartIndex[num] = i;

            // leading?
            if (numToStartIndex.contains(num+1))
                numToStartIndex[num+1] = numToStartIndex[num];
        }

        int longest = 0;
        for (auto [num, start_i] : numToStartIndex) {
            int end = num;
            if (nums[start_i] == num) {
                while (numToStartIndex.contains(end)) { end++; }
                longest = max(longest, end - num);
            }
        }
        return longest;     
    }
};
