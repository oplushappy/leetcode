class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        auto it = max_element(candies.begin(), candies.end());
        int maximum = *it;
        vector<bool> ans(candies.size(), false);
        for(int i = 0; i < candies.size(); i++) {
            if((candies[i] + extraCandies) >= maximum) ans[i] = true;
        }
        return ans;
    }
};