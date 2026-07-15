// looping
//  O(N)
class Solution {
public:
    double myPow(double x, int n) {
        bool neg = false;
        if (n < 0) {
            n = abs(n);
            neg = true;
        }
        double res = 1.0;
        while (n--) {
            res *= x;
        }
        return neg ? 1.0/res : res;
    }
};
