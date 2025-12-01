class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<pair<int, int>> st;
        
        for(int i = 0; i <= temperatures.size() - 1; i++) {
            int t = temperatures[i];
            while(!st.empty() && t > st.top().second) {
                int index = i - st.top().first;
                res[st.top().first] = index;
                st.pop();
            }
            st.push({i, t});
        }
        return res;
    }
};