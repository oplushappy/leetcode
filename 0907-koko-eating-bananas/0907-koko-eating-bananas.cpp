class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        auto res = *max_element(piles.begin(), piles.end());

        while(l <= r) {
            int k = (l + r) / 2;
            long long hours = 0;
            for(auto ele : piles) {
                hours += (ele + k - 1) / k;
            }
            
            if(hours <= h) {
                res = min(res, k);
                r = k - 1;
            } else {
                l = k + 1;
            }
        }

        return res;
    }
};