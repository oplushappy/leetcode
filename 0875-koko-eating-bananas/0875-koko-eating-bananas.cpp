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
    int minEatingSpeed(vector<int>& piles, int h) {
        int m = piles.size();
        sort(piles.begin(), piles.end());
        return get_first_match(1, piles[m - 1], [&](int num) {
            unsigned long total = 0;
            for(const auto &p : piles) {
                // total += ceil((double)p / num);
                total += p / num;
                if((p % num) != 0) total += 1;
            }
            return total <= h;
        });
    }
};