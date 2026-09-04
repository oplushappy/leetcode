class Solution {
public:
    int hammingWeight(int n) {
        int total = 0;
        while(n) {
            n = n & (n-1);
            total++;
        }
        return total;
    }
};