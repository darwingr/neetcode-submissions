// Freq maps, track uniques (have/need), -1 for not found index
//  O(M + N)
//  O(uniqs(m, n))
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";
        unordered_map<char,int> t_freqs;
        for (char c : t)
            t_freqs[c]++;

        unordered_map<char,int> s_freqs;
        int need = t_freqs.size();
        int have = 0;
        pair<int,int> ss = {-1, -1};
        auto ss_len = [&]() {return ss.first < 0 ? 0 : ss.second - ss.first + 1;};
        int l = 0;
        for (int r=0; r<s.size(); r++) {
            char sr = s[r];
            s_freqs[sr]++;
            if (t_freqs.contains(sr) && s_freqs[sr] == t_freqs[sr])
                have++;

            while (have == need) {
                if (ss_len() == 0 || r - l + 1 < ss_len())
                    ss = {l, r};
                
                char sl = s[l];
                if (t_freqs.contains(sl) && s_freqs[sl] == t_freqs[sl])
                    have--;
                s_freqs[sl]--;
                l++;
            }
        }
        return ss_len() == 0 ? "" : s.substr(ss.first, ss_len());
    }
};
