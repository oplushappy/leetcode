# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        level = defaultdict(int)
        def dfs(root, depth):
            if root is None:
                return
            level[depth] += root.val
            dfs(root.left, depth + 1)
            dfs(root.right, depth + 1)
            return
        
        dfs(root, 1)
        
        return max(level, key=level.get)