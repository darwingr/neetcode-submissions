// union find
//  1. 
class Solution {
    vector<int> rank;
    vector<int> parent;
    int graph_count;

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        graph_count = n;
        rank = vector<int>(n, 0);
        parent = vector<int>(n);
        for (int i=0; i<n; i++)
            parent[i] = i;

        for (auto& e : edges)
            if (!unite(e.front(), e.back()))
                return false;
        return graph_count == 1;
    }

    bool unite(int u, int v) {
        int gu = find(u);
        int gv = find(v);
        if (gu == gv)
            return false;
        else
            graph_count--;

        if (rank[gu] > rank[gv])
            swap(gu, gv);
        parent[gu] = gv;
        rank[gv] += rank[gu];

        return true;
    }
    
    int find(int node) {
        while (node != parent[node]) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }
};
