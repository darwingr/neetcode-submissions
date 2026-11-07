// Dijkstra: 
//  O(E log V)
//  O(V + E)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> edges;
        for (const auto& t : times)
            edges[t[0]].emplace_back(t[1], t[2]);

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<>
                    > minHeap;
        minHeap.push({0, k});
        unordered_set<int> visited;
        int max_delay = 0;
        while (!minHeap.empty()) {
            auto [elapsed, source]= minHeap.top();
            minHeap.pop();

            if (visited.contains(source))
                continue;
            visited.insert(source);
            max_delay = elapsed;

            if (edges.contains(source))
                for (auto [target, travel] : edges[source])
                    if (!visited.contains(target))
                        minHeap.push({elapsed + travel, target});
        }

        return visited.size() == n ? max_delay : -1;
    }
};
