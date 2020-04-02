# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def traverse(link: ListNode):
    while link:
        print(link.val)
        link = link.next


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        newLink = ListNode(0)
        cur = newLink
        while l1 and l2: # 这个地方一定要是与，否则遇到空节点对结果有影响
            if l1.val < l2.val:
                cur.next = l1
                cur = l1
                l1 = l1.next
            else:
                cur.next = l2
                cur = l2
                l2 = l2.next

        if l1 == None:
            cur.next = l2

        if l2 == None:
            cur.next = l1

        return newLink.next

'''
def main():
    node1_1 = ListNode(1)
    node1_2 = ListNode(2)
    node1_3 = ListNode(4)
    node1_1.next = node1_2
    node1_2.next = node1_3

    node2_1 = ListNode(1)
    node2_2 = ListNode(3)
    node2_3 = ListNode(4)
    node2_1.next = node2_2
    node2_2.next = node2_3

    link1 = node1_1
    link2 = node2_1

    solution = Solution()
    traverse(link1)
    print('*********')
    traverse(link2)
    print('*********')

    traverse(solution.mergeTwoLists(link1, link2))
    print('*********')


if __name__ == '__main__':
    main()
'''