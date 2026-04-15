// Bucket Sorting
//  O()
//  O()
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> val_freq;
        for (int n : nums)
            val_freq[n]++;
        
        vector<vector<int>> freq_vals(nums.size()+1);
        for (auto [k, v] : val_freq)
            freq_vals[v].push_back(k);

        vector<int> result;
        for (int i=freq_vals.size()-1; i>=0 && k; i--)
            for (int j=0; j<freq_vals[i].size() && k; j++, k--)
                result.push_back(freq_vals[i][j]);
        return result;
    }
};
