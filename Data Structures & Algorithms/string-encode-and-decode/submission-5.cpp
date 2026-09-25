class Solution {
public:

    string encode(vector<string>& strs) {
        string enc = "";
        if (strs.size() < 10)
            enc.push_back('0');
        enc += to_string(strs.size());
        for (auto& str : strs) {
            if (str.size() < 10)
                enc.push_back('0');
            if (str.size() < 100)
                enc.push_back('0');

            enc += to_string(str.size());
            enc += str;
        }
        return enc;
    }

    vector<string> decode(string s) {
        int w_count = stoi(s.substr(0, 2));
        vector<string> strs;
        size_t pos = 2;
        for (size_t i=0; i<w_count; i++) {
            int w_size = stoi(s.substr(pos, 3));
            pos += 3;
            strs.push_back(s.substr(pos, w_size));
            pos += w_size;
        }
        return strs;
    }
};
