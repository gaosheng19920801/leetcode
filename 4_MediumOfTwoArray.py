class Solution:
    def findMedianSortedArrays(self, nums1: [], nums2: []) -> float:
        for item in nums1:
            nums2.append(item)
        nums2.sort()
        length = len(nums2)
        if length % 2 == 0:
            i = length // 2
            return (nums2[i - 1] + nums2[i]) / 2
        else:
            i = length // 2
            return nums2[i]

    '''
    参考链接：https://leetcode.wang/leetCode-4-Median-of-Two-Sorted-Arrays.html
    '''

    def findMedianSortedArrays_2(self, nums1: [], nums2: []) -> float:
        m = len(nums1)
        n = len(nums2)

        if m > n:
            return self.findMedianSortedArrays_2(nums2, nums1)

        iMin = 0
        iMax = m
        while iMin <= iMax:
            i = (iMax + iMin) // 2
            j = (m + n + 1) // 2 - i
            if j != 0 and i != m and nums2[j - 1] > nums1[i]:  # 增大i
                iMin = i + 1
            elif i != 0 and j != n and nums1[i - 1] > nums2[j]:  # 减小i
                iMax = i - 1
            else:
                maxLeft = 0
                if i == 0:
                    maxLeft = nums2[j - 1]
                elif j == 0:
                    maxLeft = nums1[i - 1]
                else:
                    maxLeft = max(nums1[i - 1], nums2[j - 1])

                if (m + n) % 2 == 1:
                    return maxLeft

                minRight = 0
                if i == m:
                    minRight = nums2[j]
                elif j == n:
                    minRight = nums1[i]
                else:
                    minRight = min(nums1[i], nums2[j])

                return (maxLeft + minRight) / 2.0

        return 0.0

'''
def main():
    nums1 = [1, 3]
    nums2 = [2, 4]
    solution = Solution()
    print(solution.findMedianSortedArrays_2(nums1, nums2))


if __name__ == '__main__':
    main()
'''