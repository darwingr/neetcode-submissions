// Dijkstra is best: 
//  O(E log V)
//  O(V + E)
class Solution {
public:
    // shortest path between k and all nodes
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // edges by origin -> (dest, time)
        unordered_map<int, vector<pair<int,int>>> edges;
        for (const auto& t : times)
            edges[t[0]].push_back({t[1], t[2]});
        
        priority_queue<
                pair<int,int>,
                vector<pair<int,int>>,
                greater<>
            > min_heap;
        min_heap.push({0, k});
        
        unordered_set<int> visited;
        int total_time = 0;
        while (!min_heap.empty()) {
            auto [w1, n1] = min_heap.top();
            min_heap.pop();
            if (visited.contains(n1))
                continue;
            visited.insert(n1);
            total_time = w1;

            if (edges.contains(n1))
                for (const auto& [n2, w2]: edges[n1])
                    if (!visited.contains(n2))
                        min_heap.push({w1 + w2, n2});
        }
        return visited.size() == n ? total_time : -1;
    }
};
