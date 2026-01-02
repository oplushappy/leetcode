# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        
        def dfs(root):
            if root is None:
                return

            if root.val == 2:
                return dfs(root.left) or dfs(root.right)
            
            if root.val == 3:
                return dfs(root.left) and dfs(root.right)

            return root.val

        return bool(dfs(root)) 