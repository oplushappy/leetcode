class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for(int i = 0; i <= n; i++) {
            int tmp = 0;
            int num = i;
            while(num) {
                if(num & 1) tmp++;
                num = num >> 1;
            }
            res[i] = tmp;
        }
        return res;
    }
};