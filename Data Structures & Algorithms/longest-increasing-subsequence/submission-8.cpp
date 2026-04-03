// tails + BINARY SEARCH: Patience Sorting
// O(N log N)
// O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // lengths2tails
        //      index k  → subsequence length = k + 1
        //      value    → smallest tail achievable for that length
        vector<int> tails;
        tails.push_back(nums[0]);

        //for (int i=1; i<nums.size(); i++) {
        for (int num : nums) {
            //int num = nums[i];

            // Can num extend the longest subseq so far?
            if (tails.back() < num)
                tails.push_back(num);
            
            // Find/Extend the best possible shorter subsequence.
            else {
                //  O(log N) - find index of first val >= nums[i]
                //  index = number of elements in tails that are strictly less than num.
                int index = ranges::lower_bound(tails, num) - tails.begin();
                //  Best tail for subsequences of size index is now num.
                tails[index] = num;
            }
        }
        return tails.size();
    }
};
