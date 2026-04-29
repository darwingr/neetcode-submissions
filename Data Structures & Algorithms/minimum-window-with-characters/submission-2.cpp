// Sliding Window: L & R, freq map 
//      1. slide right until overlapping
//      2. Then increment left if overlapping, right if not
//  O(s chars +  unique chars)
//  O(unique chars)
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_freqs;
        for (char c : t)
            t_freqs[c]++;

        unordered_map<char, int> s_freqs;
        int overlap = 0;

        string best = "";

        // 1. Slide R right until overlapping
        int r = 0;
        while (r < s.size()) {
            char c = s[r];
            s_freqs[c]++;
            if (s_freqs[c] <= t_freqs[c]) {
                overlap++;
                if (overlap == t.size()) {
                    best = s.substr(0, r + 1);
                    break;
                }
            }
            r++;
        }

        // 2. If non-overlapping, slide R, otherwise slide L
        int l = 0;
        while (r < s.size()) {// && r-l+1 >= t.size()) {
            // incrementing r
            if (overlap < t.size()) {
                r++;
                if (r == s.size())
                    break;
                char c = s[r];
                s_freqs[c]++;
                if (s_freqs[c] <= t_freqs[c]) {
                    overlap++;
                    if (overlap == t.size()) {
                        auto ss = s.substr(l, r - l + 1);
                        if (ss.size() < best.size())
                            best = ss;
                    }
                }
            }
            // incrementing L, shrinking
            else {
                char c = s[l];
                s_freqs[c]--;
                l++;

                if (s_freqs[c] < t_freqs[c])
                    overlap--;
                else {
                    auto ss = s.substr(l, r - l + 1);
                    if (ss.size() < best.size())
                        best = ss;
                }
            }
        }
        return best;
    }
};
