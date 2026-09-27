class Solution {
    template<typename T, typename M>
    T get_first_match(T lo, T hi, M match) {
        while(lo <= hi) {
            T mid = lo + (hi - lo) / 2;
            if(match(mid)) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    }
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = get_first_match(0, n - 1, [&](int idx){
            return nums[idx] >= target;
        });
        if(ans == n || nums[ans] != target) return -1;
        return ans;
    }
};