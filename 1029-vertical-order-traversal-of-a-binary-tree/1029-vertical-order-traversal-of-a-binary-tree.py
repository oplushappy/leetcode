# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        map = []

        def dfs(root, r, c):
            if root is None:
                return
            
            map.append((c, r, root.val))
            
            dfs(root.left, r + 1, c - 1)
            dfs(root.right, r + 1, c + 1)
        
        dfs(root, 0, 0)
        map.sort()


        ansMap = defaultdict(list)
        for col, row, key in map:
            ansMap[col].append(key)
        
        ans = []
        for key in sorted(ansMap):
            ans.append(ansMap[key]) 
        
        return ans



