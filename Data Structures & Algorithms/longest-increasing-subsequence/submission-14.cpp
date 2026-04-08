// DP + Binary search
//  O(N log N)
//  O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails{nums[0]};

        for (int n : nums) {
            if (n > tails.back())
                tails.push_back(n);
            
            else {
                int index =  ranges::lower_bound(tails, n) - tails.begin();
                tails[index] = n;
            }
        }
        return tails.size();
    }
};
