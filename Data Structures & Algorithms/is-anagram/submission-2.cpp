class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> freqs;
        if (s.size() != t.size())
            return false;

        for (char c : s)
            freqs[c]++;

        for (char c : t) {
            if (!freqs.contains(c))
                return false;
            else {
                freqs[c]--;
                if (freqs[c] == 0)
                    freqs.erase(c);
            }
        }
        return freqs.empty();
    }
};
