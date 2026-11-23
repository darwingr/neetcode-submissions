class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (!ranges::contains(wordList, endWord))
            return 0;
        // intermediates
        unordered_map<string, vector<string>> patternWords;
        for (string& w : wordList)
            for (size_t i=0; i<w.size(); i++) {
                string pattern{w};
                pattern[i] = '+';
                patternWords[pattern].push_back(w);
            }

        int steps = 1;
        unordered_set<string> visited;
        visited.insert(beginWord);
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            int breadth = q.size();
            while (breadth--) {
                string w = q.front();
                q.pop();
                if (w == endWord)
                    return steps;
                for (int i=0; i<w.size(); i++) {
                    string patt{w};
                    patt[i] = '+';
                    for (string& neighbor : patternWords[patt])
                        if (!visited.contains(neighbor)) {
                            q.push(neighbor);
                            visited.insert(neighbor);
                        }
                }
            }
            steps++;
        }

        return 0;
    }
};
