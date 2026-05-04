// bin search between 1 and max(piles)
#include <ranges>
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min_k = 1;
        int max_k = ranges::max(piles);
        int best_k = max_k;

        while (min_k <= max_k) {
            int k = (min_k + max_k) / 2;

            long long time = 0;
            for (int p : piles)
                time += ceil(static_cast<double>(p) / k);

            if (time <= h) {
                best_k = k;
                max_k = k - 1;
            } else
                min_k = k + 1;
        }
        return best_k;        
    }
};
