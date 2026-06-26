class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> t_freqs;
        int max_freq = 0;
        for (char t : tasks) {
            t_freqs[t]++;
            max_freq = max(max_freq, t_freqs[t]);
        }
        
        int max_freq_count = 0;
        for (auto [_, freq] : t_freqs)
            if (freq == max_freq)
                max_freq_count++;

        int time = (max_freq - 1) * (n + 1) + max_freq_count;
        return max((int) tasks.size(), time);
    }
};
