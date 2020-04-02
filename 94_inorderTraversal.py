# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def inorderTraversal(self, root: TreeNode) -> list:
        cur = root
        ret_list = []
        temp_list = []
        while cur or len(temp_list) > 0:
            while cur:
                temp_list.append(cur)
                cur = cur.left
            cur = temp_list.pop(-1)
            ret_list.append(cur.val)
            cur = cur.right

        return ret_list

'''
def main():
    node1 = TreeNode(1)
    node2 = TreeNode(2)
    node3 = TreeNode(3)

    node1.left = None
    node1.right = node2
    node2.left = node3
    node2.right = None

    tree = node1

    solution = Solution()

    print(solution.inorderTraversal(tree))


if __name__ == '__main__':
    main()
'''