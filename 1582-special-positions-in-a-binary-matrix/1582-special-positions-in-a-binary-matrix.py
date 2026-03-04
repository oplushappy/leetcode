class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        row = [sum(r) for r in mat]
        col = [sum(mat[i][j] for i in range(len(mat))) for j in range(len(mat[0]))]

        ans = 0
        for i in range(len(mat)):
            for j in range(len(mat[0])):
                if mat[i][j] == 1 and row[i] == 1 and col[j] == 1:
                    ans += 1
        
        return ans
