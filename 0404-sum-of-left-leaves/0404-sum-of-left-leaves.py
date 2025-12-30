# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        # 邊界 子樹空，返回0
        if root is None:
            return 0
        # 子問題 左邊左節點sum + 右邊右節點sum
        ans = self.sumOfLeftLeaves(root.left) + self.sumOfLeftLeaves(root.right)
        # 非邊界 
        left = root.left
        if left is not None and left.left is None and left.right is None:
            ans += left.val
        
        return ans
        