# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        def dfs(root, depth):
            if root is None:
                return

            if depth == len(ans):
                ans.append(root.val)

            dfs(root.right, depth + 1)
            dfs(root.left, depth + 1)

            return

        dfs(root, 0)
        return ans
             
