// Sets
//  O(N)
//  O(N)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> seen_once;
        unordered_set<int> seen_twice;
        for(int n : nums) {
            if (seen_once.contains(n)) {
                seen_once.erase(n);
                seen_twice.insert(n);
            } else
                seen_once.insert(n);
        }
        return *seen_once.begin();
    }
};
