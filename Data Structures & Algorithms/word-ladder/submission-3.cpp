class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (!ranges::contains(wordList, endWord))
            return 0;

        // Generate patterns
        unordered_map<string, vector<string>> patternWords;
        for (const string& w : wordList)
            for (size_t i=0; i<w.size(); i++) {
                string pattern{w};
                pattern[i] = '+';
                patternWords[pattern].push_back(w);
            }

        // BFS
        int steps = 1;
        unordered_set<string> visited{beginWord};
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            size_t breadth = q.size();
            while (breadth--) {
                string w = q.front();
                q.pop();
                visited.insert(w);
                if (w == endWord)
                    return steps;
    
                for (size_t i=0; i<w.size(); i++) {
                    string pattern{w};
                    pattern[i] = '+';

                    for (string nei : patternWords[pattern])
                        if (!visited.contains(nei)) {
                            q.push(nei);
                            visited.insert(nei);
                        }
                }

            }
            steps++;
        }
        return 0;
    }
};
