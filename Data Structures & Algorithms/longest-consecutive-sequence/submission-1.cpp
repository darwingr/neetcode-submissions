// HASH STARTS
//  O(N)
//  O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> seq_start;
        for (int n : nums) {
            if (seq_start.contains(n-1))
                //seq_start[n] = max(seq_start[n], seq_start[n-1]+1);
                seq_start[n] = seq_start[n-1]+1;
            else
                seq_start[n] = n;
        }

        int biggest = 0;
        for (auto [num, start] : seq_start)
            if (num == start) {
                int count = 1;
                while (seq_start.contains(++start)) count++;
                biggest = max(biggest, count);
            }

        return biggest;
    }
};
