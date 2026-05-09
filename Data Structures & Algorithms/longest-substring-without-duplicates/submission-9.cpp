// Set for freqs, Track longest
//  O(len)
//  O(uniqs)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        unordered_set<char> chars;
        
        int l = 0;
        for (int r = 0; r<s.size(); r++) {
            while (chars.contains(s[r])) {
                chars.erase(s[l]);
                l++;
            }
            chars.insert(s[r]);
            longest = max(longest, (int) chars.size());
        }
        
        return longest;
    }
};
