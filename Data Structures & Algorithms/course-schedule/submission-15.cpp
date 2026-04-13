// Find cycles & prune
//  O(V + E)
//  O(V + E)
class Solution {
    vector<vector<int>> prereqs;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        prereqs = vector(numCourses, vector<int>());
        for (auto cp : prerequisites)
            prereqs[cp[0]].push_back(cp[1]);

        for (int i=0; i<numCourses; i++) {
            unordered_set<int> visited;
            if (containsCycle(i, visited))
                return false;
        }
        return true;
    }

    // dfs
    bool containsCycle(int course, unordered_set<int>& visited) {
        if (visited.contains(course))
            return true;
        if (prereqs[course].empty())
            return false;
        visited.insert(course);

        for (int p : prereqs[course])
            if (containsCycle(p, visited))
                return true;

        prereqs[0].clear();
        visited.erase(course);
        return false;
    }
};
