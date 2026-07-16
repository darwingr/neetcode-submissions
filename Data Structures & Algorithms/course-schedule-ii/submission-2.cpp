// Cycle Detection (DFS)
class Solution {
    vector<vector<int>> prereqs;
    vector<vector<int>> courses;
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // impossible: cycles

        prereqs = vector<vector<int>>(numCourses, vector<int>());
        courses = vector<vector<int>>(numCourses, vector<int>());
        for (auto pre : prerequisites) {
            int course = pre.front();
            int prereq = pre.back();
            prereqs[course].push_back(prereq);
            courses[prereq].push_back(course);
        }

        
        vector<int> res;
        vector<bool> visited(numCourses);
        // roots: have 0 prereqs, are required in courses
        //  count depths, find cycles
        //  iterate through those with no prereqs
        for (int i = 0; i<numCourses; i++) {
            if (visited[i] || courses[i].size() > 0)
                continue;
            unordered_set<int> path;
            if (!dfs(visited, res, i, path))
                return {};
        }

        // leaves: have prereqs, 0 required courses
        // orphans last: 0 & 0
        return res;
    }

    // true if not a cycle
    bool dfs(vector<bool>& visited, vector<int>& res, int start, unordered_set<int>& path) {
        if (path.contains(start))
            return false;
        if (visited[start])
            return true;
        
        path.insert(start);
        for (int next : prereqs[start]) {
            if (!dfs(visited, res, next, path))
                return false;
        }


        path.erase(start);
        visited[start] = true;
        res.push_back(start);
        return true;
    }
};
