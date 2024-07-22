# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # Create a dummy node which acts as the previous node of the head
        dummy = ListNode(0)
        dummy.next = head

        # Initialize a pointer to the dummy node
        point = dummy

        # Traverse the list while there are at least two more nodes to process
        while point.next is not None and point.next.next is not None:
            # Identify the two nodes to swap
            swap1 = point.next
            swap2 = point.next.next

            # Perform the swap
            swap1.next = swap2.next  # swap1's next points to the node after swap2
            swap2.next = swap1  # swap2's next points to swap1
            point.next = (
                swap2  # point's next points to swap2 (which is now before swap1)
            )

            # Move the pointer two nodes ahead for the next swap
            point = swap1

        # Return the new head of the list, which is dummy's next node
        return dummy.next


# Helper function to convert a list to a linked list
def list_to_linkedlist(arr):
    if not arr:
        return None
    head = ListNode(arr[0])
    current = head
    for val in arr[1:]:
        current.next = ListNode(val)
        current = current.next
    return head


# Helper function to convert a linked list to a list
def linkedlist_to_list(head):
    arr = []
    current = head
    while current:
        arr.append(current.val)
        current = current.next
    return arr


# Helper function to print a linked list
def print_linkedlist(head):
    current = head
    while current:
        print(current.val, end=" -> " if current.next else "")
        current = current.next
    print()


# Test cases
test_cases = [
    [1, 2, 3, 4],  # Even number of nodes
    [1, 2, 3],  # Odd number of nodes
    [],  # Empty list
    [1],  # Single node
    [1, 2],  # Two nodes
    [1, 2, 3, 4, 5, 6],  # Multiple nodes with an even number of nodes
]

solution = Solution()

for i, test in enumerate(test_cases):
    print(f"Test case {i + 1}: {test}")
    head = list_to_linkedlist(test)
    print("Original linked list:")
    print_linkedlist(head)
    swapped_head = solution.swapPairs(head)
    print("Swapped linked list:")
    print_linkedlist(swapped_head)
    print()
