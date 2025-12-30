# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        
        def dfs(root):  
            if root is None:
                return []
          
            ans = []

            if root.left is None and root.right is None:
                ans.append((root.val, 1))
                return ans
            
            for num , length in dfs(root.left):
                ans.append((root.val * (10 ** length) + num, length + 1))

            for num , length in dfs(root.right):
                ans.append((root.val * (10 ** length) + num, length + 1))

            return ans

        res = dfs(root)
        return sum(num for num, _ in res)