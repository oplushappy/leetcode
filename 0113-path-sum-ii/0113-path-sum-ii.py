# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        ans = []
        path = []
        curSum = 0
        def dfs(root):
            if root is None:
                return
            
            path.append(root.val)
            nonlocal curSum
            curSum += root.val

            if root.left is None and root.right is None:
                if curSum == targetSum:
                    ans.append(path.copy())
            else:
                dfs(root.left)
                dfs(root.right)
            
            path.pop()
            curSum -= root.val
        
        dfs(root)
        return ans