// Sliding Window: map char positions
//  O(string len)
//  O(unique chars)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r = 0;
        int l = 0;
        unordered_map<char, int> char_position;
        int longest = 0;
        while (r < s.size()) {
            char c = s[r];
            if (char_position.contains(c))
                l = max(l, char_position[c] + 1);
            char_position[c] = r;
            longest = max(longest, r - l + 1);
            r++;
        }
        return longest;
    }
};
