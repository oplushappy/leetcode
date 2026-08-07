class Solution {
public:
    vector<pair<int, int>> dirs = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        queue<pair<int, int>> q;
        auto visited = vector(m, vector(n, false));
        q.emplace(sr, sc);
        auto inside = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n; 
        };
        int initialC = image[sr][sc];

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            image[x][y] = color;
            visited[x][y] = true;
            for(auto [dx, dy] : dirs) {
                int ddx = x + dx, ddy = y + dy;
                if(!inside(ddx, ddy)) continue;
                if(image[ddx][ddy] != initialC) continue;
                if(visited[ddx][ddy]) continue;
                q.emplace(ddx, ddy);
            }
        }
        return image;
    }
};