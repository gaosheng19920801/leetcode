class Solution:
    def maxArea(self, height: []) -> int:
        maxarea = 0
        l = 0
        r = len(height) - 1

        while l < r:
            maxarea = max(maxarea, min(height[l], height[r]) * (r - l))

            if height[l] < height[r]:
                l += 1
            else:
                r -= 1

        return maxarea

'''
def main():
    list = [1, 8, 6, 2, 5, 4, 8, 3, 7]
    solution = Solution()
    print(solution.maxArea(list))


if __name__ == '__main__':
    main()
'''