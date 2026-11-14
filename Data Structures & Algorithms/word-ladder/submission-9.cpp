class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (!ranges::contains(wordList, endWord))
            return 0;

        unordered_map<string, vector<string>> wordsBy;
        for (string& w : wordList)
            for (size_t i=0; i<w.size(); i++) {
                string pattern{w};
                pattern[i] = '+';
                wordsBy[pattern].push_back(w);
            }

        unordered_set<string> visited{beginWord};
        queue<string> q;
        q.push(beginWord);
        int count = 1;
        while (!q.empty()) {
            int breadth = q.size();
            while (breadth--) {
                string w = q.front();
                q.pop();
                if (w == endWord)
                    return count;
                for (size_t i=0; i<w.size(); i++) {
                    string pattern{w};
                    pattern[i] = '+';
                    for (string nei : wordsBy[pattern]) {
                        if (!visited.contains(nei)) {
                            visited.insert(nei);
                            q.push(nei);
                        }
                    }
                }
            }
            count++;
        }

        return 0;
    }
};
