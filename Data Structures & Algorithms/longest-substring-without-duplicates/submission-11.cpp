// map old pos to avoid while loop
//  O(len)
//  O(uniqs)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, size_t> char_pos;
        size_t longest = 0;
        size_t l = 0;
        for (size_t r = 0; r<s.size(); r++) {
            if (char_pos.contains(s[r]))
                l = max(l, char_pos[s[r]] + 1);

            char_pos[s[r]] = r;
            longest = max(longest, r - l + 1);
        }
        return longest;
    }
};

