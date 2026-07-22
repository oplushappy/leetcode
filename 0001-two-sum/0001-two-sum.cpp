class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        auto temp = nums;
        sort(temp.begin(), temp.end());
        int i = 0, j = n - 1;
        while(i <= j) {
            int sum = temp[i] + temp[j];
            if(sum > target) j--;
            else if(sum < target) i++;
            else break;
        }
        vector<int> ans;
        for(int k = 0; k < n; k++) {
            if(nums[k] == temp[i] || nums[k] == temp[j]) {
                ans.push_back(k);
            }
        }
        return ans;
    }
};