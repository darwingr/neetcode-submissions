// XOR^: cancels out itself, stays same with 0
//  O(N)
//  O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int n : nums)
            res ^= n;
        return res;
    }
};
