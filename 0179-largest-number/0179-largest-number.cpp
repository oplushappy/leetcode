class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> sNum;
        for(const auto& num : nums) {
            sNum.push_back(to_string(num));
        }
        sort(sNum.begin(), sNum.end(), [&](const string &s1, const string &s2){
            return s1 + s2 > s2 + s1;
        });

        if(sNum[0] == "0") return "0";

        string res = "";
        for(auto &s : sNum) {
            res += s;
        }
        return res;
    }
};