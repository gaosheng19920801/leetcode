class Solution:
    def numTrees(self, n: int) -> int:
        if n == 0:
            return 0

        def getAns(start: int, end: int):
            num = 0
            if start >= end:  # 只有一个数字的时候
                return 1

            i = start
            while i <= end:
                tree_lefts_num = getAns(start, i - 1)
                tree_rights_num = getAns(i + 1, end)

                num += tree_lefts_num * tree_rights_num

                i += 1
            return num

        return getAns(1, n)


def main():
    solution = Solution()
    print(solution.numTrees(3))


if __name__ == '__main__':
    main()
