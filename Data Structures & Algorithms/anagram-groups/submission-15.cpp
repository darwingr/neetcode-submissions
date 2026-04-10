class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagroups;
        for (string& word : strs) {
            auto code = alphaCount(word);
            anagroups[code].push_back(word);
        }
        vector<vector<string>> result;
        for (auto& [_, anag] : anagroups)
            result.push_back(anag);
        return result;
    }


    string alphaCount(string& word) {
        vector<int> counts(26);
        for (char c : word)
            counts[c - 'a']++;
        string code;
        for (int n : counts) {
            code += to_string(n);
            code += ',';
        }


        return code;
    }
};
