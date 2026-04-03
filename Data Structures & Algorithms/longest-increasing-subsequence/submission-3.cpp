class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails(nums.size());
        int len = 0;

        for (int x : nums) {
            int pos = lower_bound(tails.begin(), tails.begin() + len, x) - tails.begin();
            tails[pos] = x;
            if (pos == len) len++;
        }
        return len;
    }
};
