// tails + BINARY SEARCH: Patience Sorting
// O(N log N)
// O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // index k  → subsequence length = k + 1
        // value    → smallest tail achievable for that length
        vector<int> tails;
        tails.push_back(nums[0]);

        int lis = 1;
        for (int i=1; i<nums.size(); i++) {
            int num = nums[i];

            // Can num extend the longest subseq so far?
            if (tails.back() < num) {
                tails.push_back(num);
                lis++;
                continue;
            }

            // Can num extend any other subsequences?
            //
            //  O(log N) - find index of first val >= nums[i]
            //  index = number of elements in tails that are strictly less than num.
            int index = ranges::lower_bound(tails, num) - tails.begin();
            //  Best tail for subsequences of size index is now num.
            tails[index] = num;
        }
        return tails.size();
    }
};
