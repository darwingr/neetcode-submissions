class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1;
        int hi = ranges::max(piles) + 1;
        // find lower bound
        while (lo < hi) {
            int speed = lo + (hi - lo) / 2;
            long long time = 0;
            for (int p : piles)
                time += ceil(static_cast<double>(p) / speed);

            if (time > h)
                lo = speed + 1;
            else
                hi = speed;
        }
        return lo;
    }
};
