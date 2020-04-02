class TreeNode:
    def __init__(self, x: int):
        self.value = x
        self.left = None
        self.right = None


class BinaryTree:
    def __init__(self, root: TreeNode):
        self.root = root

    '''
    先序遍历：根---左---右
    采用栈，将节点压入栈，每次取出一个节点，并输出，判断左右节点是否为空，先存右节点再存左节点
    '''

    def preOderTraveral(self, root: TreeNode):
        ret_list = []
        stack = [root]
        node = stack.pop()
        while node:
            ret_list.append(node.value)

            if node.right:
                stack.append(node.right)

            if node.left:
                stack.append(node.left)

            if len(stack) != 0:
                node = stack.pop()
            else:
                break

        print(ret_list)
        return ret_list

    '''中序遍历
    中序遍历：左---根---右：
    1、采用栈，将根节点和所有节点的左节点存入栈
    2、然后依次从栈中取节点并输出，并判断右节点，如果右节点不为空，则把右子节点及其右节点的所有左子节点放入栈
    '''

    def inOderTraveral(self, root: TreeNode):
        ret_list = []
        stack = []

        while root or len(stack):
            if root:  # 当当前节点不为空时，将其左子树全部加入到栈中
                stack.append(root)
                root = root.left
            else:  # 当左子树为空，从栈中取节点并判断是右子树
                if len(stack):
                    root = stack.pop()
                    ret_list.append(root.value)
                    root = root.right

        print(ret_list)

        return ret_list

    '''后序遍历
    后序遍历：左---右----根
    1、采用两个栈A和B，将根节点存入栈A
    2、从栈中取节点，将其放入栈B，判断该节点左节点，左节点不为空，将左节点存入A，右节点不为空将右节点放入A
    3、最后将栈B中的元素按照先进后出的方式进行输出
    '''

    def postOderTraveral(self, root: TreeNode):
        stack_A = []  # 存放节点
        stack_B = []  # 存放需要输出的节点
        ret_list = []  # 返回后续遍历的列表

        while len(stack_A) or root:
            stack_B.append(root.value)
            if root.left:
                stack_A.append(root.left)
            if root.right:
                stack_A.append(root.right)

            if len(stack_A):
                root = stack_A.pop()
            else:  # 这个地方当栈为空时，节点没有了，需要给节点附空值，不然无法结束循环，因为栈A中最后一个节点被取出时，栈为空，但是root不为空
                root = None

        while len(stack_B):
            ret_list.append(stack_B.pop())

        print(ret_list)

        return ret_list

    '''层次遍历
    层次遍历：
    1、采用队列，将root存入
    2、判断队列是否为空，并取出不为空的节点，将左右孩子也放入队列中，然后打印
    '''

    def PrintFromTopToBottom(self, root: TreeNode):
        queue = [] # 采用队列存节点，先进先出
        ret_list = []
        if root is None:
            return []

        while root:
            ret_list.append(root.value)
            if root.left:
                queue.append(root.left)

            if root.right:
                queue.append(root.right)

            if len(queue):
                root = queue.pop(0)
            else:
                root = None

        print(ret_list)

        return ret_list


def main():
    root = TreeNode(0)
    node1 = TreeNode(1)
    node2 = TreeNode(2)
    node3 = TreeNode(3)
    node4 = TreeNode(4)
    node5 = TreeNode(5)
    node1.left = node3
    node1.right = node4
    node2.right = node5
    root.left = node1
    root.right = node2

    binaryTree = BinaryTree(root)

    binaryTree.preOderTraveral(root)
    binaryTree.inOderTraveral(root)
    binaryTree.postOderTraveral(root)
    binaryTree.PrintFromTopToBottom(root)

    return True


if __name__ == '__main__':
    main()
