// Leading string count, char count delimiters
//  O(all_chars)
//  O(all_chars + strings)   includes space to store lengths
class Solution {
public:

    string encode(vector<string>& strs) {
        string out;
        // 2 chars for string count, strings < 100
        if (strs.size() < 10)
            out.append("0");
        out.append(to_string(strs.size()));
        for (string& str : strs) {
            // 3 chars for string length, len < 200
            if (str.size() < 10)
                out.append("00");
            else if (str.size() < 100)
                out.append("0");
            out.append(to_string(str.size()));
            out.append(str);
        }
        return out;
    }

    vector<string> decode(string s) {
        int string_count = stoi(s.substr(0, 2));
        int offset = 2;
        vector<string> decoded;
        for (int i=0; i<string_count; i++) {
            int size = stoi(s.substr(offset, 3));
            string str = s.substr(offset+3, size);
            decoded.push_back(str);
            offset += 3 + size;
        }
        return decoded;
    }
};
