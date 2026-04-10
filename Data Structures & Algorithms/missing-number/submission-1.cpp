class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expect_sum = nums.size();
        int actual_sum = 0;
        for (int i=0; i<nums.size(); i++) {
            expect_sum += i;
            actual_sum += nums[i];
        }
        return expect_sum - actual_sum;
    }
};
