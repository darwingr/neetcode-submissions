//  O(n)
//  O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int max = ranges::max(nums); // O(n) time
        vector<bool> seen(max+1);   // O(n) space
        for (int n : nums) {
            if (seen[n])
                return n;
            else
                seen[n] = true;
        }

        return 0;
    }
};
