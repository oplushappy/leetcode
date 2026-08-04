class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        minimum = 0
        for i in range(1, len(strs)):
            if(len(strs[i]) < len(strs[minimum])):
                minimum = i

        tmp = ''
        index = 1
        flag = False
        for c in strs[minimum]:
            tmp2 = tmp
            tmp2 += c
            for str in strs:
                if tmp2 != str[:index]:
                    flag = True
            if flag: 
                return tmp
            else :
                tmp += c
                index += 1
        return tmp