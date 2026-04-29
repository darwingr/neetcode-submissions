// Sliding Window: track best buy & max profit
//  O(N)
//  O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int best_buy = prices.front();
        int maxp = 0;
        
        for (int price : prices) {
            int profit = price - best_buy;
            maxp = max(maxp, profit);
            best_buy = min(best_buy, price);
        }

        return maxp;
    }
};
