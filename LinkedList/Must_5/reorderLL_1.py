class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: ListNode) -> None:
        # Base case: if the list is empty or has only one node, no reordering needed
        if head is None or head.next is None:
            return

        # Initialize two pointers to find the middle of the list
        p1 = head  # Pointer p1 starts from the head of the list
        p2 = head  # Pointer p2 also starts from the head of the list

        # Move p2 to the end of the list, and p1 to the middle
        while p2.next is not None and p2.next.next is not None:
            p1 = p1.next  # Move p1 one step forward
            p2 = p2.next.next  # Move p2 two steps forward

        # p1 now points to the node before the middle
        preMiddle = p1
        preCurrent = p1.next  # The first node of the second half of the list

        # Reverse the second half of the list
        while preCurrent.next is not None:
            current = preCurrent.next  # The node to be moved
            preCurrent.next = current.next  # Skip the node being moved
            current.next = (
                preMiddle.next
            )  # Insert the node at the start of the second half
            preMiddle.next = current  # Update the head of the reversed second half

        # Now p1 points to the end of the first half
        p1 = head
        p2 = preMiddle.next  # Start of the reversed second half

        # Merge the two halves
        while p1 != preMiddle:
            preMiddle.next = p2.next  # Save the next node of the reversed second half
            p2.next = p1.next  # Insert the next node from the first half
            p1.next = p2  # Insert the current node from the second half
            p1 = p2.next  # Move to the next node in the first half
            p2 = preMiddle.next  # Move to the next node in the reversed second half

        # At the end, preMiddle.next should be None as it was reversed and merged


def create_linked_list(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for value in values[1:]:
        current.next = ListNode(value)
        current = current.next
    return head


def print_linked_list(head):
    while head:
        print(head.val, end=" -> " if head.next else "\n")
        head = head.next


def test_reorder_list():
    solution = Solution()

    # Test Case 1: Reorder list [1, 2, 3]
    head = create_linked_list([1, 2, 3])
    solution.reorderList(head)
    print("Test Case 1 Result: ", end="")
    print_linked_list(head)  # Expected Output: 1 -> 3 -> 2

    # Test Case 2: Reorder list [1, 2, 3, 4, 5]
    head = create_linked_list([1, 2, 3, 4, 5])
    solution.reorderList(head)
    print("Test Case 2 Result: ", end="")
    print_linked_list(head)  # Expected Output: 1 -> 5 -> 2 -> 4 -> 3

    # Test Case 3: Reorder list [1, 2, 3, 4]
    head = create_linked_list([1, 2, 3, 4])
    solution.reorderList(head)
    print("Test Case 3 Result: ", end="")
    print_linked_list(head)  # Expected Output: 1 -> 4 -> 2 -> 3

    # Test Case 4: Reorder list with only one node [1]
    head = create_linked_list([1])
    solution.reorderList(head)
    print("Test Case 4 Result: ", end="")
    print_linked_list(head)  # Expected Output: 1

    # Test Case 5: Reorder an empty list []
    head = create_linked_list([])
    solution.reorderList(head)
    print("Test Case 5 Result: ", end="")
    print_linked_list(head)  # Expected Output: (no output, as the list is empty)

    # Test Case 6: Reorder list [1, 2, 3, 4, 5, 6]
    head = create_linked_list([1, 2, 3, 4, 5, 6])
    solution.reorderList(head)
    print("Test Case 6 Result: ", end="")
    print_linked_list(head)  # Expected Output: 1 -> 6 -> 2 -> 5 -> 3 -> 4


# Run test cases
test_reorder_list()
