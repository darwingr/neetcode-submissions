#include <ranges>
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        digits.back()++;
        int carry = 0;
        for (int& d : digits | views::reverse){
            d += carry;
            carry = 0;
            if (d > 9) {
                carry = d / 10;
                d = d % 10;
            }
        }
        if (carry)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};
