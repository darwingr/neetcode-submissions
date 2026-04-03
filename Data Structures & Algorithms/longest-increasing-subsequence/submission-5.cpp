// tails + BINARY SEARCH: Patience Sorting
// O(N log N)
// O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        tails.push_back(nums[0]);

        int lis = 1;
        for (int i=1; i<nums.size(); i++) {
            int num = nums[i];

            if (tails.back() < num) {
                tails.push_back(num);
                lis++;
                continue;
            }

            // O(log N)
            // find index of first val >= nums[i]
            int index = ranges::lower_bound(tails, num)
                      - tails.begin();
            tails[index] = num;
        }
        return lis;
    }
};
