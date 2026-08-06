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
        int res = get_first_match(0, n, [&](int idx){
            if(idx < n && idx >= 0) {
                return nums[idx] >= target;
            }
            return false;
        });
        if(res < n && res >= 0) {
            return nums[res] == target ? res : -1;
        } else {
            return -1;
        }
        // return res;
    }
};