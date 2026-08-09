class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);
        for(auto edge : edges) {
            int a = edge[0], b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(degree[i] == 1) q.push(i);
        }

        int remaining = n;
        while(remaining > 2) {
            int size = q.size();
            remaining -= size;
            for(int i = 0; i < size; i++) {
                int u = q.front();
                q.pop();
                for(auto v : graph[u]) {
                    degree[v]--;
                    if(degree[v] == 1) q.push(v);
                }
            }
        }

        vector<int> res;
        while(!q.empty()) {
            int e = q.front();
            q.pop();
            res.push_back(e);
        }
        return res;
    }
};