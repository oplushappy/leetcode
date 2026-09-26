class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> l(n, -1), r(n, -1);
        int leftMax = height[0];
        int rightMax = height[n - 1];
        for(int i = 0; i < n; i++) {
            if(height[i] < leftMax) l[i] = leftMax;
            leftMax = max(leftMax, height[i]);
        }
        for(int i = n - 1; i >= 0; i--) {
            if(height[i] < rightMax) r[i] = rightMax;
            rightMax = max(rightMax, height[i]);
        }
        int area = 0;
        for(int i = 0; i < n; i++) {
            if(l[i] == -1 || r[i] == -1) continue;
            area += min(l[i], r[i]) - height[i];
        }
        return area;
    }
};