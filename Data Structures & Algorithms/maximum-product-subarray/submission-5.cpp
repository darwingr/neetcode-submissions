// KADANES!
//  O(N)
//  O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int best = nums.front();
        int min_prod = 1;
        int max_prod = 1;

        for (int n : nums) {
            auto options = {
                n,
                n * min_prod,
                n * max_prod
            };
            min_prod = min(options);
            max_prod = max(options);
            best = max(best, max_prod);
        }
        return best;
    }
};
