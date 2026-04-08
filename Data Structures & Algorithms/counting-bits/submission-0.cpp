// FORMULA!!!
// O(N)
// O(N)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> counts(n+1);
        for (int i=0; i<=n; i++) {
            counts[i] = __builtin_popcount(i);
        }
        return counts;
    }
};
