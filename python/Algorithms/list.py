class ListNode:

    def __init__(self, val):
        self.val = val
        self.next = None

    def __eq__(self, other):

        if not isinstance(other, list):
            return False

        node = self
        for i in other:
            if i != node.val:
                return False
            node = node.next

        return True

    @staticmethod
    def from_list(lst):
        if len(lst) == 0:
            return

        head = ListNode(0)
        n = head
        for i in lst:
            n.next = ListNode(i)
            n = n.next

        return head.next
