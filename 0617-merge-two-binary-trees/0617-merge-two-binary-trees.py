# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(root1, root2):
            if root1 is None and root2 is None:
                return None
            
            if root1 is None:
                return root2
            
            if root2 is None:
                return root1
            
            new_node = TreeNode(val=root1.val + root2.val)

            new_node.left = dfs(root1.left, root2.left)
            new_node.right = dfs(root1.right, root2.right)

            return new_node
        
        return dfs(root1, root2)