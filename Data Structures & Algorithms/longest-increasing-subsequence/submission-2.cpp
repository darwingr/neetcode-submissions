class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);

        int lis = 1;
        for (int i=1; i<nums.size(); i++) {
            if (dp.back() < nums[i]) {
                dp.push_back(nums[i]);
                lis++;
                continue;
            }

            int index = ranges::lower_bound(dp, nums[i])
                      - dp.begin();
            dp[index] = nums[i];
        }

        return lis;
    }
};
