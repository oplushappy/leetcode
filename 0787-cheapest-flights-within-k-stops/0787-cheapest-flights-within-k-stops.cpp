class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto &f : flights) {
            int from = f[0], to = f[1], price = f[2];
            graph[from].emplace_back(to, price);
        }
        
        using tii = tuple<int, int, int>; // dis, u, k
        priority_queue<tii, vector<tii>, greater<tii>> q;
        q.emplace(0, src, -1);

        auto min_dist = vector(n, vector(k + 2, INT_MAX));
        min_dist[src][0] = 0;

        while(!q.empty()) {
            auto [dis, u, step] = q.top();
            q.pop();
            if(u == dst) return dis;
            if(step == k) continue;
            for(auto [v, price] : graph[u]) {  
                if(dis + price < min_dist[v][step + 1]) {
                    min_dist[v][step + 1] = dis + price;
                    q.emplace(min_dist[v][step + 1], v, step + 1);
                }
            }
        }
        return -1;
    }
};