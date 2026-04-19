// Kahn's/Topo Sort: adj & indegrees
//  O(V + E + N)
//  O(V + E)
class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        // find all unique chars
        for (string& w : words)
            for (char c : w)
                indegree[c] = 0;

        // Find orders:
        //  Build the adjacency list, count indegrees
        for (int i=0; i<words.size()-1; i++) {
            string w1 = words[i];
            string w2 = words[i+1];

            int minLen = min(w1.size(), w2.size());
            // shorter equal prefix must be first
            if (w1.size() > w2.size()
                    && w1.substr(0, minLen) == w2.substr(0, minLen))
                return "";
            
            for (int j=0; j<minLen; j++) {
                char c1 = w1[j], c2 = w2[j];
                if (c1 != c2) {
                    if (!adj[c1].contains(c2)) {
                        adj[c1].insert(c2);
                        indegree[c2]++;
                    }
                    break;
                }
            }
        }

        // find the root nodes, of all unique chars
        queue<char> q;
        for (auto [c, deg] : indegree)
            if (deg == 0)
                q.push(c);

        // BFS
        string out;
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            out += c;
            for (char nei : adj[c]) {
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        return out.size() == indegree.size() ? out : "";
    }
};
