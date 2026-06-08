class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> set;
        for (auto& n : nums) {
            if (set.count(n))
                return true;
            else
                set.insert(n);
        }
        return false;
    }
};