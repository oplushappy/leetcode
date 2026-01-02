# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        map = defaultdict(int)

        def dfs(root):
            if root is None:
                return 0
            
            root.val += dfs(root.left) + dfs(root.right)
            map[root.val] += 1

            return root.val
        
        dfs(root)
        ans = defaultdict(list)
        for key, val in map.items():
            ans[val].append(key)
        
        maxKey = max(ans.keys())
        return ans[maxKey]
