//  O(n)
//  O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lo = 0;
        int hi = 0;
        int maxp = 0;
        for (size_t i=1; i<prices.size(); i++) {
            //if (prices[i] >= prices[hi])
            //    hi = i;
            maxp = max(maxp, prices[i] - prices[lo]);
            if (prices[i] < prices[lo])
                lo = i;
        }

        return maxp;
    }
};
