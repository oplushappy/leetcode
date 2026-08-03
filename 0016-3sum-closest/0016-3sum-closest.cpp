class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closetSum = nums[0] + nums[1] + nums[2];
        for(int i = 0; n - i >= 3; i++) {
            int l = i + 1, r = n - 1;
            while(l < r) {
                int curSum = nums[i] + nums[l] + nums[r];
                if(abs(target - curSum) < abs(target - closetSum)) closetSum = curSum;

                if(curSum > target) {
                    r--;
                } else if(curSum < target) {
                    l++;
                } else {
                    return curSum;
                }
            }
        }
        return closetSum; 
    }
};