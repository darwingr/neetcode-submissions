class Solution {
    vector<int> bests;
public:
    int rob(vector<int>& nums) {
        bests = vector<int>(nums.size() + 2, -1);
        return rob(nums, nums.size() - 1);
    }

private:
    int rob(vector<int>& nums, int start) {
        bests[start] = max(
            nums[start] + max(0, bests[start+2]),
            max(0, bests[start+1])
        );
        if (start == 0)
            return bests[0];
        else
            return rob(nums, start - 1);
    }
};
