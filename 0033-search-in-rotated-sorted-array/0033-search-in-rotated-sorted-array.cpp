class Solution {
public:
    template<typename T, typename M>
    T get_first_match(T lo, T hi, M match) {
        while(lo <= hi) {
            T mid = lo + (hi - lo) / 2;
            if(match(mid)) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    };
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int rightest = nums[n - 1];
        int spot = get_first_match(0, n - 1, [&](int idx) {
            return nums[idx] <= rightest;
        });
        int res1 = get_first_match(0, spot - 1, [&](int idx) {
            return nums[idx] >= target;
        });
        int res2 = get_first_match(spot, n - 1, [&](int idx) {
            return nums[idx] >= target;
        });
        if(res1 < n && nums[res1] == target) return res1;
        else if(res2 < n && nums[res2] == target) return res2;
        else return -1;
    }
};