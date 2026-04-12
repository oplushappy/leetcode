class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        z, o, diff = [0] * n, [0] * n, [0] * n
        cnt0 = cnt1 = 0

        for i in range(n):
            if s[i] == '0': cnt0 += 1
            else: cnt1 += 1
            z[i], o[i], diff[i] = cnt0, cnt1, cnt1 - cnt0

        res = 0
        ind, ind0, ind1 = {0:-1}, {}, {}

        for i in range(n):
            pref = diff[i]

            if pref in ind:
                res = max(res, i - ind[pref])
            
            # take 1 inside
            if (pref + 2) in ind:
                j = ind[pref + 2]
                sub1 = o[i] - (o[j] if j >= 0 else 0)
                if cnt1 > sub1: res = max(res, i - j)
                elif (pref + 2) in ind1: res = max(res, i - ind1[pref+2])
            
            if (pref - 2) in ind:
                j = ind[pref - 2]
                sub0 = z[i] - (z[j] if j >= 0 else 0)
                if cnt0 > sub0: res = max(res, i - j)
                elif (pref - 2) in ind0: res = max(res, i - ind0[pref-2])

            
            if pref not in ind: ind[pref] = i
            if pref not in ind0 and z[i] > 0: ind0[pref] = i
            if pref not in ind1 and o[i] > 0: ind1[pref] = i

        return res
        
        