// Sliding Window: char freqs, find longest at each R & track longest
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> char_freqs;
        int longest = 0;
        int l = 0;
        int maxf = 0;
        
        for (int r=0; r < s.size(); r++) {
            char_freqs[s[r]]++;
            maxf = max(maxf, char_freqs[s[r]]);
            
            while ((r - l + 1) - maxf > k) {
                char_freqs[s[l]]--;
                l++;
            }
            longest = max(longest, r - l + 1);
        }
        
        return longest;
    }
};
