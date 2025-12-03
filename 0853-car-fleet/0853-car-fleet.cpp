class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> p;
        vector<float> st;
        for(int i = 0; i < position.size(); i++) {
            p.push_back({position[i], speed[i]});
        }

        sort(p.rbegin(), p.rend());

        for(auto &ele : p) {
            st.push_back((float)(target - ele.first) / ele.second);
            if(st.size() >= 2 && st.back() <= st[st.size() - 2]) {
                st.pop_back();
            }
        }
        
        return st.size();
    }
};