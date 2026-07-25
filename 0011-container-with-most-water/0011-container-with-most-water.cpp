class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int vol = 0;
        while(l < r) {
            int w = r - l;
            if(height[l] < height[r]) {
                vol = max(vol, (height[l] * w));
                l++;
            } else {
                vol = max(vol, (height[r] * w));
                r--;
            }
        }
        return vol;
    }
};