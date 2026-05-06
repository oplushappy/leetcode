class Solution:
    def rotateTheBox(self, boxGrid: List[List[str]]) -> List[List[str]]:
        # [i, j], [j, rows - 1 - i]
        # every row move
        rows = len(boxGrid)
        cols = len(boxGrid[0])

        for row in range(rows):
            empty = cols - 1
            
            for col in range(cols - 1, -1, -1):
                if boxGrid[row][col] == '*':
                    empty = col - 1
                elif boxGrid[row][col] == '#':
                    boxGrid[row][empty], boxGrid[row][col] = boxGrid[row][col], boxGrid[row][empty]
                    empty -= 1
        
        result = [[0] * rows for _ in range(cols)]
        for i in range(rows):
            for j in range(cols):
                result[j][rows - 1 - i] = boxGrid[i][j]
        
        return result