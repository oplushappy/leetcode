class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return a < b;
        });
    }
};