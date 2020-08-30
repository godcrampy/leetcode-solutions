class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []

        res = [[1]]
        for i in range(2, numRows + 1):
            temp = []
            for j in range(i):
                temp.append(self.get(res[-1], j - 1) + self.get(res[-1], j))
            res.append(temp)

        return res

    def get(self, l: List[int], index: int):
        if index < 0 or index >= len(l):
            return 0
        return l[index]
