class Solution:
    def twoSum(self, nums: [], target: int):
        i = 0
        ret_list = []
        length = len(nums)
        num1 = 0
        while i < length:
            num1 = target - nums[i]
            if num1 in nums:
                index = nums.index(num1)
                if index != i:
                    ret_list.append(i)
                    ret_list.append(index)
                    return ret_list

            i += 1

        return ret_list
'''

def main():
    nums = [2, 7, 11, 15]
    target = 9

    solution = Solution()

    ret = solution.twoSum(nums,target)

    print(ret)


if __name__ == '__main__':
    main()
'''