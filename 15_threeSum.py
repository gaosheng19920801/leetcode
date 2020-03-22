class Solution:
    def threeSum(self, nums: list):
        ret_list = []
        length = len(nums)
        if length < 2:
            return ret_list

        nums.sort(reverse=False)  # 升序
        i = 0
        for i in range(length):
            if nums[i] > 0:  # 当第一个大于0 后面的数则全部大于0
                return ret_list
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            l = i + 1
            r = length - 1
            while l < r:
                if nums[i] + nums[l] + nums[r] == 0:
                    ret_list.append([nums[i], nums[l], nums[r]])

                    while l < r and nums[l] == nums[l + 1]: # l<r一定要判断 防止越界
                        l += 1
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    l += 1
                    r -= 1
                else:
                    if nums[i] + nums[l] + nums[r] > 0:
                        r -= 1
                    else:
                        l += 1
            i += 1
        return ret_list

'''
def main():
    nums = [-1, 0, 1, 2, -1, -4]
    solution = Solution()

    ret_list = solution.threeSum(nums)

    print(ret_list)

    nums1 = [0, 0, 0]
    ret_list = solution.threeSum(nums1)

    print(ret_list)


if __name__ == '__main__':
    main()
'''