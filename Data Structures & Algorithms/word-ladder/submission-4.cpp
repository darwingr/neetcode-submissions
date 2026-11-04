class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (!ranges::contains(wordList, endWord))
            return 0;
        
        // precomp patterns
        unordered_map<string, vector<string>> pattern_words;
        for (const string& w : wordList) 
            for (size_t i=0; i<w.size(); i++) {
                string pattern{w};
                pattern[i] = '+';
                pattern_words[pattern].push_back(w);
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
                if (w == endWord)
                    return steps;
                
                for (size_t i=0; i<w.size(); i++) {
                    string pattern = w;
                    pattern[i] = '+';
                    for (const string& nei : pattern_words[pattern]) {
                        if (!visited.contains(nei)) {
                            q.push(nei);
                            visited.insert(nei);
                        }
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};
