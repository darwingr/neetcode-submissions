class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size())
            return false;
        
        unordered_map<char, int> s1_freqs;
        for (char c : s1)
            s1_freqs[c]++;

        unordered_map<char, int> s2_freqs;
        int matches = 0;
        int l = 0;
        int r = 0;
        while (r < s2.size()) {
            char sr = s2[r];
            if (!s1_freqs.contains(sr)) {
                r++;
                l = r;
                s2_freqs.clear();
                matches = 0;
                continue;
            }

            s2_freqs[sr]++;
            if (s1_freqs[sr] == s2_freqs[sr])
                matches++;

            if (r - l + 1 < s1.size()) {
                r++;
            } else if (matches == s1_freqs.size())
                return true;
            else {
                char sl = s2[l];
                if (s1_freqs[sl] == s2_freqs[sl])
                    matches--;
                s2_freqs[sl]--;
                l++;
                r++;
            }
        }
        return false;
    }
};
