# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    def printList(self):
        while self:
            print(self.val)
            self = self.next


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummyHead = ListNode(0)
        currNode = dummyHead
        carry = 0
        while l1 or l2:
            if l1:
                x = l1.val
            else:
                x = 0

            if l2:
                y = l2.val
            else:
                y = 0

            sum = x + y + carry
            carry = sum // 10
            currNode.next = ListNode(sum % 10)
            currNode = currNode.next

            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next

        if carry > 0:
            currNode.next = ListNode(carry)

        return dummyHead.next


'''
def main():
    num1 = ListNode(2)
    num1.next = ListNode(4)
    num1.next.next = ListNode(3)

    num2 = ListNode(5)
    num2.next = ListNode(6)
    num2.next.next = ListNode(4)

    solution = Solution()

    result = solution.addTwoNumbers(num1,num2)

    result.printList()

    print('end')


if __name__ == '__main__':
    main()
'''
