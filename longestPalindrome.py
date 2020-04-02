# 参考链接：https://www.cnblogs.com/xiaochuan94/archive/2019/06/04/10971443.html
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) < 2:
            return s

        # 1、预处理数据，在数据间加'#‘，首尾加'$''@'
        t = '$'
        for elem in s:
            t += '#' + elem

        t += '#@'
        # 2、计算数组p,起始索引，最长回文半径
        n = len(t)
        p = [0 for i in range(n)]
        id = 0
        mx = 0
        maxLength = -1
        index = 0
        j = 1
        while j < n - 1:
            if mx > j:
                p[j] = min(p[2 * id - j], mx - j)
            else:
                p[j] = 1

            # 向左右两边延伸，拓展右边界
            while t[j + p[j]] == t[j - p[j]]:
                p[j] += 1

            # 判断回文的右边界是否超过mx，如果超过了需要更新mx和id的值
            if mx < p[j] + j:
                mx = p[j] + j
                id = j

            # 判断是否为最大的回文字符串，如果是更新maxLength和index值
            if maxLength < p[j] - 1:
                maxLength = p[j] - 1
                index = j

            j += 1

        start = (index - maxLength) // 2
        return s[start:start + maxLength]

'''
def main():
    s = 'cabbaf'
    solution = Solution()
    print(solution.longestPalindrome(s))


if __name__ == '__main__':
    main()
'''