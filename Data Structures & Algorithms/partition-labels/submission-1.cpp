// Greedy: map lr bounds for each char,
//         reiterate tracking next_end from latest string char
//  O(N)
//  O(1) - since max 26 letters is constant
class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<size_t,size_t>> char_lr;
        for (size_t i=0; i<s.size(); i++) {
            if (char_lr.contains(s[i]))
                char_lr[s[i]].second = i;
            else
                char_lr[s[i]] = {i, i};
        }

        vector<int> lengths;
        size_t l = 0;
        size_t next_end = 0;
        for (size_t r=0; r<s.size(); r++) {
            auto [char_l, char_r] = char_lr[s[r]];
            next_end = max(next_end, char_r);
            // found end
            if (r == next_end) {
                lengths.push_back(r - l + 1);
                l = r + 1;
            }
        }

        return lengths;
    }
};
