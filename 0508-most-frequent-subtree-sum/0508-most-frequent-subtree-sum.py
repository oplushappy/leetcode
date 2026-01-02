# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        counter = defaultdict(int)

        def dfs(root):
            if root is None:
                return 0
            
            root.val += dfs(root.left) + dfs(root.right)
            counter[root.val] += 1

            return root.val
        
        dfs(root)
        
        maxFreq = max(counter.values())
        return [s for s, freq in counter.items() if freq == maxFreq]
