# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if not head or not head.next or k == 0:
            return head

        # find length
        n = 1
        tail = head
        while tail.next:
            tail = tail.next
            n += 1

        # reduce k
        k %= n
        if k == 0:
            return head

        # make circular
        tail.next = head

        # find new tail
        step = n - k # new head position
        newTail = head
        for _ in range(step - 1):
            newTail = newTail.next
        
        # break
        head = newTail.next
        newTail.next = None

        return head


        
