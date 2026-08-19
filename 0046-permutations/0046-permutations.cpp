class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;

        int n = nums.size();
        auto visited = vector(n, false);
        auto backtrack = [&](auto &self) {
            if(tmp.size() == n) {
                res.push_back(tmp);
                return;
            }
            for(int i = 0; i < n; i++) {
                if(visited[i]) continue;
                visited[i] = true;
                tmp.push_back(nums[i]);

                self(self);

                visited[i] = false;
                tmp.pop_back();
            }
        };
        backtrack(backtrack);
        return res;
    }
};