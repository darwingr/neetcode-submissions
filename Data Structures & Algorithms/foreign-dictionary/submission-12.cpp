// Kahn/Topo Sort: track ajd and indegree (uniques)
class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        for (string& w : words) 
            for (char c : w)
                indegree[c] = 0;
        
        // Find char orders
        for (int i=0; i<words.size()-1; i++) {
            string& w1 = words[i];
            string& w2 = words[i+1];
            int minLen = min(w1.size(), w2.size());
            // Abort if impossible
            if (w1.size() > w2.size()
                    && w1.substr(0, minLen) == w2.substr(0, minLen))
                return "";

            //  Build adj/indegree
            for (int j=0; j<minLen; j++) {
                char c1 = w1[j];
                char c2 = w2[j];
                //if (c1 != c2 && !adj[c1].contains(c2)) {
                if (c1 != c2) {
                    if (!adj[c1].contains(c2)){
                        adj[c1].insert(c2);
                        indegree[c2]++;
                    }
                    break;
                }
            }
        }

        // find parents
        queue<char> q;
        for (auto [c, deg] : indegree)
            if (deg == 0)
                q.push(c);
        
        string alphabet;
        // BFS
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            alphabet += c;
            for (char nei : adj[c]) {
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }
        bool complete_alphabet = alphabet.size() == indegree.size();
        return complete_alphabet ? alphabet : "";
    }
};
