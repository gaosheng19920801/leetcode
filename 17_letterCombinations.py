class Solution:
    # 采用递归的方法
    def letterCombinations(self, digits: str):
        if not digits:
            return []

        index = 0
        ret_list = []
        keys = [" ", "*", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

        def combination(src: str, cur: str, id: int):
            if id == len(src):
                ret_list.append(cur)
                return

            s = keys[int(src[id])]

            for i in range(len(s)):
                combination(src, cur + s[i], id + 1)
                i += 1

        combination(digits, "", 0)

        return ret_list

    # 采用队列的方法
    def letterCombinations_1(self, digits: str):
        if not digits:
            return []

        ret_list = [""]
        keys = [" ", "*", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        i = 0
        res = 0

        while i < len(digits):
            res = len(ret_list)
            s = keys[int(digits[i])]
            k = 0
            while k < res:
                temp = ret_list.pop(0)
                j = 0
                while j < len(s):
                    ret_list.append(temp + s[j])
                    j += 1
                k += 1

            i += 1

        return ret_list

'''
def main():
    solution = Solution()
    #  print(solution.letterCombinations("234"))
    print(solution.letterCombinations_1("234"))


if __name__ == '__main__':
    main()
'''