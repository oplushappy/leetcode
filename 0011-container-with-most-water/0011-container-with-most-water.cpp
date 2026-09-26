class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int l = 0, r = n - 1;
        while(l < r) {
            int h = min(height[l], height[r]);
            int w = r - l;
            ans = max(ans, h * w);
            if(height[l] < height[r]) {
                int tmp = height[l];
                while(l < r && tmp >= height[l+1]) l++;
                l++;
            } else {
                int tmp = height[r];
                while(l < r && tmp > height[r-1]) r--;
                r--;
            }
        }
        return ans;
    }
};