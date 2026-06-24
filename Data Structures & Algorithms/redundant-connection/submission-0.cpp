// DFS Cycle detection
//      adjacency list, cycle set, visited list
//  O(V + E)
//  O(V + E)
#include <ranges>
class Solution {
    vector<bool> visited;
    vector<vector<int>> adj;
    unordered_set<int> cycle;
    int cycle_start;

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        visited = vector<bool>(n + 1, false);
        adj = vector<vector<int>>(n + 1);
        cycle.clear();

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cycle_start = -1;
        dfs(1, -1);

        for (auto& edge : edges | views::reverse) {
            int u = edge[0];
            int v = edge[1];
            if (cycle.contains(u) && cycle.contains(v))
                return {u, v};
        }
        return {};
    }

    // finds the cycle
    bool dfs(int node, int predecessor) {
        if (visited[node]) {
            cycle_start = node;
            return true;
        }

        visited[node] = true;
        for (int nei : adj[node]) {
            if (nei == predecessor)
                continue;
            if (dfs(nei, node)) {
                if (cycle_start != -1)
                    cycle.insert(node);
                if (cycle_start == node)
                    cycle_start = -1;
                return true;
            }
        }
        return false;
    }
};
