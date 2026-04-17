// Kahn's / TOPO SORT - BFS DAG
//      adjadency list:  map char -> {char}
//      indegree counts: map char -> int
//  O(N + V + E)
//  O(V + E)
class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        // initialize:
        //      lower letters point to higher
        //      lowest letters have no indegree
        unordered_map<char, unordered_set<char>> adj; // O(E)
        unordered_map<char, int> indegree;  // O(V)
        // find all unique chars - O(N)
        for (string w : words)
            for (char c : w)
                indegree[c] = 0;
        
        // iterate words - O([words]) = O(E)
        for (int i=0; i<words.size()-1; i++) {
            string w1 = words[i], w2 = words[i+1];

            // unsolvable order: w1 longer with prefix == w2
            int minLen = min(w1.size(), w2.size());
            if (w1.size() > w2.size()
                    && w1.substr(0, minLen) == w2.substr(0, minLen))
                return "";

            // find adjacencies & count indegrees
            for (int j=0; j<minLen; j++) {
                char c1 = w1[j], c2 = w2[j];
                if (c1 != c2) {
                    if (!adj[c1].contains(c2)) {
                        adj[c1].insert(c2);
                        indegree[c2]++;
                    }
                    break; // done for these words
                }
            }
        }

        // find lowest letters to start
        queue<char> q;
        for (auto [c, degree] : indegree)
            if (degree == 0)
                q.push(c);

        // BFS down the DAG: build the output
        string res;
        while (!q.empty()) {
            // output the char
            char c = q.front();
            q.pop();
            res += c;

            // queue the children only if they're orphans
            for (char nei : adj[c]) {
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        // Solvable if result contains all unique chars
        return res.size() == indegree.size() ? res : "";
    }
};
