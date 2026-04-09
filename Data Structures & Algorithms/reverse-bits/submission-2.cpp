// O(1)
// O(1)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        int bit = 32;
        while (bit--) {
            int lsb =  n % 2 == 0 ? 0 : 1;
            res += lsb * pow(2, bit);
            n = n >> 1;
        }
        return res;
    }
};
