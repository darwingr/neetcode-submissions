class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        int bits = 32;
        while (bits--) {
            n % 2 == 0 ? : count++;
            n = n >> 1;
        }

        return count;
    }
};
