//  O(1)
//  O(1)
class Solution {
public:
    int reverse(int x) {
        string xs = to_string(abs(x));
        long inv = 0;
        for (int i = 0; i<xs.size(); i++) {
            inv += (xs[i] - '0') * static_cast<long>(powl(10, i));
        }
        if (x < 0) inv = -inv;
        if (inv < INT32_MIN || INT32_MAX < inv)
            return 0;
        return inv;
    }
};
