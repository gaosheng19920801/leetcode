# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

    def add(self,ln:ListNode):
        while ls:
            ls = ls.next



# class Solution:
#    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:


def main():
    head = ListNode(0)
    temp = head
    i = 1
    while i < 6:
        node = ListNode(i)
        temp = node
        temp = temp.next
        i += 1

    while head.next:
        print(head.val)
        head = head.next
    print(head.val)


if __name__ == '__main__':
    main()
