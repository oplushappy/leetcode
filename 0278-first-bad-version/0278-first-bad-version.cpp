// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

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
    int firstBadVersion(int n) {
        return get_first_match(1, n, [&](int idx) {
            return isBadVersion(idx);
        });
    }
};