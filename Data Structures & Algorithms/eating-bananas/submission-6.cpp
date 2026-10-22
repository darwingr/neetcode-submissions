class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = ranges::max(piles) + 1;

        while (lo < hi) {
            int k = lo + (hi - lo) / 2;
            
            long long time = 0;
            for (int pile : piles)
                time += (static_cast<double>(pile) + k - 1) /k;

            if (time > h)
                lo = k + 1;
            else
                hi = k;
        }
        return lo;
    }
};
