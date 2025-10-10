"""
Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
"""

def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:

    if not head or k == 0:
        return head

    ptr = head
    n = 0 # to calc length of list
    
    # to store last node of the list
    last_node = None

    while ptr:
        n += 1
        last_node = ptr
        ptr = ptr.next

    ptr = head
    k = k % n
    if k == 0:
        return head

    # to reach a point after which all nodes will be placed in the front
    for _ in range(n - k - 1):
        ptr = ptr.next

    new_head = ptr.next
    ptr.next = None
    last_node.next = head

    return new_head