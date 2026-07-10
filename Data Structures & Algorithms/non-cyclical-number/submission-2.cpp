// Hash Set
//  O(log N)
//  O(log N)
class Solution {
    unordered_set<int> seen;
public:
    bool isHappy(int n) {
        seen.clear();
        while (n != 1) {
            if (isCyclical(n))
                return false;
            n = sos(n);
        }
        return true;
    }

    int sos(int n) {
        int sum = 0;
        while (n) {
            sum += powl(n % 10, 2);
            n /= 10;
        }
        return sum;
    }

    // true if more than one '1'
    bool isCyclical(int n) {
        if (seen.contains(n))
            return true;
        seen.insert(n);
        
        int ones = 0;
        while (n && ones < 2) {
            if (n % 10 == 1)
                ones++;
            n /= 10;
        }
        return ones >= 2;
    }
};
