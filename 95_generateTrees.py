# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
# 解法一：递归
    def generateTrees(self, n: int) -> list:
        if n == 0:
            return []

        def getAns(start: int, end: int):
            ret_list = []
            if start > end:  # 为空的时候
                ret_list.append(None)
                return ret_list

            if start == end:  # 只有一个数字的时候
                ret_list.append(TreeNode(start))
                return ret_list

            i = start
            while i <= end:
                tree_lefts = getAns(start, i - 1)
                tree_rights = getAns(i + 1, end)

                for letftree in tree_lefts:
                    for righttree in tree_rights:
                        root = TreeNode(i)
                        root.left = letftree
                        root.right = righttree
                        ret_list.append(root)

                i += 1
            return ret_list

        return getAns(1, n)


# 层次遍历 采用队列  先进先出
def print_tree(root: TreeNode):
    ret_list = []
    stack = []
    stack.append(root)
    while len(stack) > 0:
        cur = stack.pop(0)

        ret_list.append(cur.val)

        if cur.left:
            stack.append(cur.left)

        if cur.right:
           stack.append(cur.right)


    print(ret_list)


def print_tree_1(root: TreeNode):
    ret_list = []
    stack = []
    stack.append(root)
    while len(stack) > 0:
        cur = stack.pop(0)

        if cur.val == -1:
            ret_list.append(None)
            continue

        ret_list.append(cur.val)

        if cur.left:
            stack.append(cur.left)
        else:
            stack.append(TreeNode(-1))

        if cur.right:
           stack.append(cur.right)
        else:
           stack.append(TreeNode(-1))

    while ret_list[-1] is  None:
        ret_list.pop(-1)

    print(ret_list)

'''
def main():
    solution = Solution()
    trees = solution.generateTrees(3)

    for tree in trees:
        print_tree(tree)

    print("****************")

    for tree in trees:
        print_tree_1(tree)



if __name__ == '__main__':
    main()
'''