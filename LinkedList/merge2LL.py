from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        # Create a dummy node to serve as the starting point of the merged list
        dummy = ListNode(0)
        # Initialize the current pointer to the dummy node
        current = dummy

        # Pointers to traverse the two input lists
        ptr1 = list1
        ptr2 = list2

        # Traverse both lists and merge them in sorted order
        while ptr1 is not None and ptr2 is not None:
            # Compare the values of the nodes pointed by ptr1 and ptr2
            if ptr1.val <= ptr2.val:
                # If ptr1's value is smaller or equal, attach ptr1 to the merged list
                current.next = ptr1
                # Move ptr1 to the next node in its list
                ptr1 = ptr1.next
            else:
                # If ptr2's value is smaller, attach ptr2 to the merged list
                current.next = ptr2
                # Move ptr2 to the next node in its list
                ptr2 = ptr2.next
            # Move the current pointer to the next node
            current = current.next

        # Attach the remaining nodes of the non-empty list, if any
        if ptr1 is not None:
            # If list1 still has nodes, attach them to the merged list
            current.next = ptr1
        else:
            # If list2 still has nodes, attach them to the merged list
            current.next = ptr2

        # Return the merged list starting from the node after dummy
        return dummy.next


# Helper function to create a linked list from a list of values
def create_linked_list(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for value in values[1:]:
        current.next = ListNode(value)
        current = current.next
    return head


# Helper function to print the linked list
def print_linked_list(head: ListNode):
    current = head
    while current:
        print(current.val, end=" -> " if current.next else "")
        current = current.next
    print()


# Test cases
def run_tests():
    # Create test lists
    list1 = create_linked_list([1, 2, 4])
    list2 = create_linked_list([1, 3, 4])

    # Initialize the Solution class
    solution = Solution()

    # Merge the two lists
    merged_list = solution.mergeTwoLists(list1, list2)

    # Print the merged list
    print("Merged List:")
    print_linked_list(merged_list)

    # Additional test cases
    list1 = create_linked_list([])
    list2 = create_linked_list([0])
    merged_list = solution.mergeTwoLists(list1, list2)
    print("Merged List:")
    print_linked_list(merged_list)

    list1 = create_linked_list([5, 10, 15])
    list2 = create_linked_list([2, 3, 20])
    merged_list = solution.mergeTwoLists(list1, list2)
    print("Merged List:")
    print_linked_list(merged_list)


# Run the test cases
run_tests()
