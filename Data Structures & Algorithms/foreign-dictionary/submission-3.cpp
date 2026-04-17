// KAHN's / BFS TOPOLOGICAL SORT - DAG / adjacency list
//  O(N + V + E)
//  O(V + E)    
//      N sum of all word chars
//      V unique chars
//      E number of edges
class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        for (string& w : words) {
            for (char c : w) {
                adj[c] = unordered_set<char>();
                indegree[c] = 0;
            }
        }

        // Fill the adjacency list and count indegrees
        for (int i=0; i < words.size()-1; i++) {
            string w1 = words[i];
            string w2 = words[i+1];
            int minLen = min(w1.size(), w2.size());
            if (w1.size() > w2.size()
                && w1.substr(0, minLen) == w2.substr(0, minLen)
            )   return "";

            for (int j=0; j<minLen; j++) {
                if (w1[j] != w2[j]) {
                    if (!adj[w1[j]].contains(w2[j])) {
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }
        }
        
        queue<char> q;
        // queue orphans?
        for (auto& [c, deg] : indegree)
            if (deg == 0)
                q.push(c);

        // output row by row
        string out;
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            out.push_back(c);

            for (char nei : adj[c]) {
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        // if all indegrees are accounted for then its valid
        if (out.size() == indegree.size())
            return out;
        else
            return "";
    }
};
