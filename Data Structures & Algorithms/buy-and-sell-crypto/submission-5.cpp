// Sliding Window
//  O(N)
//  O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;

        int bestbuy = prices.front(); // so far
        int maxp = 0;

        for (int i=1; i<prices.size(); i++) {
            int profit = prices[i] - bestbuy;
            maxp = max(profit, maxp);
            bestbuy = min(bestbuy, prices[i]);
        }

        return maxp;
    }
};
