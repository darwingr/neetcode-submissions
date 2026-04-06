// KADANES - DP
//  O(N)
//  O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int best_prod = nums.front();
        int min_prod = 1;
        int max_prod = 1;

        for (int i=0; i<nums.size(); i++) {
            auto opts = {
                nums[i],
                nums[i] * max_prod,
                nums[i] * min_prod
            };
            max_prod = max(opts);
            min_prod = min(opts);
            best_prod = max(best_prod, max_prod);
        }

        return best_prod;
    }
};
