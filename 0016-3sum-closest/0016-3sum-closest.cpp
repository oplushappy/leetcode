class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<pair<int, int>> tmp;
        for(int i = 0; n - i >= 3; i++) {
            int l = i + 1, r = n - 1;
            while(l < r) {
                int curSum = nums[i] + nums[l] + nums[r];
                if(curSum > target) {
                    r--;
                } else if(curSum < target) {
                    l++;
                } else {
                    return curSum;
                }
                tmp.emplace_back(abs(target - curSum), curSum);
            }
        }
        return min_element(tmp.begin(), tmp.end())->second;   
    }
};