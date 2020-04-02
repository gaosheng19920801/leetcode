class Solution:
    def isValid(self, s: str) -> bool:
        temp_list = []
        i = 0
        while i < len(s):
            if s[i] == '(' or s[i] == '[' or s[i]=='{':
                temp_list.append(s[i])
            else:
                if len(temp_list) > 0:
                    temp = temp_list.pop(-1);
                    if s[i] == ')' and temp != '(':
                        return False
                    elif s[i] == ']' and temp != '[':
                        return False
                    elif s[i] == '}' and temp != '{':
                        return False
                    else:
                        i += 1
                        continue
                else:
                    return False
            i += 1

        if len(temp_list) > 0:
            return False
        else:
            return True
'''
def main():
    str1 = '()[][]{}'
    str2 = '({)}[]'

    solution = Solution()
    print(solution.isValid(str1))
    print(solution.isValid(str2))

if __name__ == '__main__':
    main()

'''