// Sliding Window: track longest, max frequency, freq per char
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> char_freqs;
        int maxfreq = 0;
        int longest = 0;

        int l = 0;
        for (int r = 0; r<s.size(); r++) {
            char_freqs[s[r]]++;
            maxfreq = max(maxfreq, char_freqs[s[r]]);
            
            while ((r - l + 1) > maxfreq + k) {
                char_freqs[s[l]]--;
                l++;
            }
            longest = max(longest, (r - l + 1));
        }
        
        return longest;
    }
};
