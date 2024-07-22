from typing import Optional


class ListNode:
    def __init__(self, data=0, next=None):
        self.data = data
        self.next = next


class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if head is None:  # If the list is empty, return head (which is None)
            return head

        odd = head  # Initialize odd pointer to the head of the list
        even = head.next  # Initialize even pointer to the second node
        evenHead = even  # Keep the head of the even nodes to link later

        while (
            even is not None and even.next is not None
        ):  # Traverse until the end of the list
            odd.next = odd.next.next  # Link odd nodes together
            odd = odd.next  # Move the odd pointer to the next odd node
            even.next = even.next.next  # Link even nodes together
            even = even.next  # Move the even pointer to the next even node

        odd.next = evenHead  # Link the last odd node to the head of the even nodes
        return head  # Return the modified list head


def print_linked_list(head):
    while head:  # Traverse the linked list
        print(head.data, end=" -> ")  # Print the current node's data
        head = head.next  # Move to the next node
    print("None")  # Indicate the end of the linked list


def create_linked_list(values):
    if not values:  # If the list of values is empty
        return None  # Return None

    head = ListNode(values[0])  # Create the head node with the first value
    current = head  # Pointer to build the linked list
    for value in values[1:]:  # Iterate over the rest of the values
        current.next = ListNode(value)  # Create a new node and link it
        current = current.next  # Move to the new node
    return head  # Return the head of the linked list


# Driver code
if __name__ == "__main__":
    solution = Solution()

    # Test Case 1: Regular list with odd and even positions
    values = [1, 2, 3, 4, 5]  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = solution.oddEvenList(head)  # Reorder the linked list
    print("Reordered list (odd-even):")
    print_linked_list(new_head)  # Print the reordered list

    # Test Case 2: List with two elements
    values = [1, 2]  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = solution.oddEvenList(head)  # Reorder the linked list
    print("Reordered list (odd-even):")
    print_linked_list(new_head)  # Print the reordered list

    # Test Case 3: Empty list
    values = []  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = solution.oddEvenList(head)  # Reorder the linked list
    print("Reordered list (odd-even):")
    print_linked_list(new_head)  # Print the reordered list

    # Test Case 4: List with one element
    values = [1]  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = solution.oddEvenList(head)  # Reorder the linked list
    print("Reordered list (odd-even):")
    print_linked_list(new_head)  # Print the reordered list

    # Test Case 5: List with duplicate values
    values = [2, 1, 3, 5, 6, 4, 7]  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = solution.oddEvenList(head)  # Reorder the linked list
    print("Reordered list (odd-even):")
    print_linked_list(new_head)  # Print the reordered list
