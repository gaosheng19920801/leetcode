# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

<<<<<<< HEAD
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
=======

class SingleLinkList(object):
    def __init__(self, node: ListNode = None):
        self.__head = node

    # 计算链表的长度
    def __len__(self):
        cur = self.__head
        count = 0
        while cur:
            count += 1
            cur = cur.next
        return count

    # 判断链表是否为空
    def isEmpty(self):
        return self.__head is None

    # 头插法
    def add(self, value):
        node = ListNode(value)
        node.next = self.__head
        self.__head = node

    # 尾插法
    def append(self, value):
        node = ListNode(value)
        node.next = None
        cur = self.__head
        if self.isEmpty():
            self.__head = node
        else:
            while cur.next:
                cur = cur.next
            cur.next = node

    # 指定插入
    def insert(self, pos, value):
        if pos <= 0:
            self.add(value)
        elif pos > len(self) - 1:
            self.append(value)
        else:
            node = ListNode(value)
            prior = self.__head
            count = 0
            while count < (pos - 1):
                prior = prior.next
                count += 1

            node.next = prior.next
            prior.next = node

    # 删除指定节点
    def remove(self, value):
        cur = self.__head
        prior = None

        while cur:
            if cur.val == value:
                if cur == self.__head:
                    self.__head = cur.next
                else:
                    prior.next = cur.next
                break
            else:
                prior = cur
                cur = cur.next

    # 遍历链表
    def traverse(self):
        cur = self.__head

        while cur:
            print(cur.val)
            cur = cur.next

    def getlist(self):
        return self.__head


class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        temp_list = []
        cur = head

        while cur:
            temp_list.append(cur)
            cur = cur.next

        length = len(temp_list)
        if length <= 1:
            return None
        elif length - n == 0:
            return head.next
        else:
            temp_list[length - n - 1].next = temp_list[length - n].next

        return head

    def removeNthFromEnd_1(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0) #防止链表为空
        dummy.next = head
        first = dummy
        second = dummy

        i = 1
        while i <= n+1:
            first = first.next
            i += 1

        while first:
            first = first.next
            second = second.next

        second.next = second.next.next

        return dummy.next
'''
def main():
    head = SingleLinkList()

    head.append(1)
    head.append(2)
    head.append(3)
    head.append(4)
    head.append(5)

    head.traverse()

    solution = Solution()

    #solution.removeNthFromEnd(head.getlist(), 2)
    solution.removeNthFromEnd_1(head.getlist(), 2)

    head.traverse()
>>>>>>> e2e0d41... code


if __name__ == '__main__':
    main()
<<<<<<< HEAD
=======
'''
>>>>>>> e2e0d41... code
