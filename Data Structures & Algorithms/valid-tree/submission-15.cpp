class UFSet {
    vector<int> rank;
    vector<int> parent;
    int _graph_count;
public:
    UFSet(int size);
    bool unite(int u, int v);
    int find(int u);
    int graph_count() const {return _graph_count;}
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UFSet ufs(n);
        for (auto& e : edges)
            if (!ufs.unite(e.front(), e.back()))
                return false;
        return ufs.graph_count() == 1;
    }
};

UFSet::UFSet(int size):
    _graph_count{size},
    rank(size, 0),
    parent(size)
{
    for (size_t i=0; i<size; i++)
        parent[i] = i;
}

bool UFSet::unite(int u, int v) {
    int gu = find(u);
    int gv = find(v);
    if (gu == gv)
        return false;
    
    _graph_count--;
    if (rank[gu] > rank[gv])
        swap(gu, gv);
    rank[gv] += rank[gu];
    parent[gu] = gv;
    return true;
}

int UFSet::find(int u) {
    while (u != parent[u]) {
        parent[u] = parent[parent[u]];
        u = parent[u];
    }
    return u;
}