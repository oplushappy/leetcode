# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        ans = []
        path = []
        def dfs(root):
            if root is None:
                path.append(None)
                return
            if root.left is None and root.right is None:
                path.append(root.val)
                ans.append('->'.join(map(str, path)))
                return

            path.append(root.val)
            dfs(root.left)
            path.pop()
            dfs(root.right)
            path.pop()
            return
        
        dfs(root)
        return ans

                