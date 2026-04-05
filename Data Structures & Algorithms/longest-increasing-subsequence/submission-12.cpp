class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails{nums[0]};
        
        for (int num : nums)
            if (num > tails.back())
                tails.push_back(num);
            else {
                int index = ranges::lower_bound(tails, num) - tails.begin();
                tails[index] = num;
            }
            
        return tails.size();
    }
};
