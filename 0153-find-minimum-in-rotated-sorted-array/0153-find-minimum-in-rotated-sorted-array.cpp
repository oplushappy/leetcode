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
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int rightest = nums[n - 1];
        int res = get_first_match(0, n - 1, [&](int idx){
            return nums[idx] <= rightest;
        });
        return nums[res];
    }
};