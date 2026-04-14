class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        preMap = {i:[] for i in range(numCourses)}
        visitSet = set()

        for cur, pre in prerequisites:
            preMap[cur].append(pre)

        def dfs(cur):
            if cur in visitSet:
                return False
            if preMap[cur] == []:
                return True
            
            visitSet.add(cur)
            for pre in preMap[cur]:
                if not dfs(pre):
                    return False
            visitSet.remove(cur)
            preMap[cur] = []

            return True

        for cur in range(numCourses):
            if not dfs(cur):
                return False
        return True