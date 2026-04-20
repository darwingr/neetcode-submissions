// Move to a Set, index doesn't matter
//  O(N)
//  O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> nSet(nums.begin(), nums.end());
        int longest = 0;

        for (int n : nSet)
            // is seq start
            if (!nSet.contains(n - 1)) {
                int length = 1;
                while (nSet.contains(n + length))
                    length++;
                longest = max(longest, length);
            }
        
        return longest;
    }
};
