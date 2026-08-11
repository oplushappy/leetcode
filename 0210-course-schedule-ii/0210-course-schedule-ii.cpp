class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto v : prerequisites) {
            int a = v[0], b = v[1];
            graph[a].push_back(b);
        }
        vector<int> state(numCourses, 0); // 0 white, 1 gray, 2 black
        vector<int> res;
        auto dfs = [&](auto &self, int u) {
            if(state[u] == 1) return false;
            if(state[u] == 2) return true;

            state[u] = 1;
            for(auto v : graph[u]) {
                if(!self(self, v)) return false;
            }

            state[u] = 2;
            if(find(res.begin(), res.end(), u) == res.end()) res.push_back(u);
            return true;
        };
        
        for(int i = 0; i < numCourses; i++) {
            if(!dfs(dfs, i)) return {};
            if(res.size() == numCourses) return res;
        }

        return res;
    }
};