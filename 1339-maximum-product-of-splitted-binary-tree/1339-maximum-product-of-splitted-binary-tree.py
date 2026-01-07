# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        nodeMax = 0
        totalSum = 0
        def total(root):
            if root is None:
                return
            nonlocal totalSum
            totalSum += root.val
            total(root.left)
            total(root.right)
            return

        def dfs(root):
            if root is None:
                return 0
            
            subSum = dfs(root.left) + dfs(root.right) + root.val
            nonlocal nodeMax
            nodeMax = max(nodeMax, (totalSum - subSum) * subSum)
            return subSum 
        
        total(root)
        dfs(root)

        return nodeMax % 1000000007