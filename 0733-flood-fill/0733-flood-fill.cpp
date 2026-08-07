class Solution {
public:
    vector<pair<int, int>> dirs = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}
    };
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size(), n = image[0].size();
        int initialC = image[sr][sc];
        if (initialC == color) return image;
        
        queue<pair<int, int>> q;
        q.emplace(sr, sc);
        image[sr][sc] = color;

        auto inside = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n; 
        };
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(auto [dx, dy] : dirs) {
                int ddx = x + dx, ddy = y + dy;
                if(!inside(ddx, ddy)) continue;
                if(image[ddx][ddy] != initialC) continue;
                image[ddx][ddy] = color;
                q.emplace(ddx, ddy);
            }
        }
        return image;
    }
};