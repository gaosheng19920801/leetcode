class Solution:
    # 解法一:滑动窗口
    def lengthOfLongestSubstring_1(self, s: str) -> int:
        str_len = len(s)
        i = 0
        j = 1
        dst_str = set()
        temp_set = set()
        max_len = 0

        while i < str_len and j < str_len:
            if s[j] in temp_set:
                temp_set.remove(s[i])
                i += 1
            else:
                temp_set.add(s[j])
                j += 1  # 此处加1，放在后面会造成‘bbbbbb’这样的字符串判断不正确，长度为0
                if max_len < j - i:
                    max_len = j - i
                    dst_str = temp_set.copy()

        return len(dst_str), dst_str

    # 解法二:将i直接跳转到重复了的字符的下一个位置，采用字典存储 字符--下标
    def lengthOfLongestSubstring_2(self, s: str) -> int:
        str_len = len(s)
        i = 0
        j = 1
        dst_str = set()
        temp_dict = {}
        max_len = 0

        while i < str_len and j < str_len:
            if temp_dict.has_key(s[i]):
                i = temp_dict[s[i]] + 1
                temp_dict.pop(s[i])
            else:
                temp_dict[s[j]] = j
                j += 1
                if max_len < j - i:
                    max_len = j - i

        return len(dst_str), dst_str

'''
def main():
    src_str = 'abcabcbb'
    solution = Solution()

    len, dst_str = solution.lengthOfLongestSubstring_1(src_str)

    print(len, dst_str)


if __name__ == '__main__':
    main()
'''