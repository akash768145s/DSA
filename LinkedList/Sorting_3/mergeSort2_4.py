class Node:
    def __init__(self, data):
        self.data = data  # Initialize the node's data
        self.next = None  # Initialize the next pointer to None


class Solution:
    # Function to sort the given linked list using Merge Sort.
    def mergeSort(self, head):
        # Base case: if the list is empty or has only one node, it is already sorted
        if not head or not head.next:
            return head

        # Function to split the linked list into two halves
        def split(head):
            slow = head  # Initialize slow pointer at the head
            fast = head  # Initialize fast pointer at the head
            prev = None  # To keep track of the node before the middle

            # Traverse the list with slow moving one step and fast moving two steps
            while fast and fast.next:
                prev = slow  # Update prev to slow
                slow = slow.next  # Move slow pointer one step forward
                fast = fast.next.next  # Move fast pointer two steps forward

            # Split the list into two halves
            prev.next = None  # Terminate the first half of the list
            return (
                head,
                slow,
            )  # Return the head of the first half and the head of the second half

        # Function to merge two sorted linked lists
        def merge(l1, l2):
            dummy = Node(0)  # Dummy node to serve as the start of the merged list
            tail = dummy  # Pointer to build the new list

            # Merge the two lists
            while l1 and l2:
                if l1.data < l2.data:  # Compare the nodes' data
                    tail.next = l1  # Link the smaller node
                    l1 = l1.next  # Move to the next node in l1
                else:
                    tail.next = l2  # Link the smaller node
                    l2 = l2.next  # Move to the next node in l2
                tail = tail.next  # Move the tail pointer to the end of the merged list

            # Append the remaining nodes of l1 or l2
            tail.next = l1 if l1 else l2
            return dummy.next  # Return the head of the merged list

        # Recursively split and merge the list
        left, right = split(head)  # Split the list into two halves
        left = self.mergeSort(left)  # Recursively sort the left half
        right = self.mergeSort(right)  # Recursively sort the right half
        return merge(left, right)  # Merge the two sorted halves


def print_linked_list(head):
    while head:  # Traverse the linked list
        print(head.data, end=" -> ")  # Print the current node's data
        head = head.next  # Move to the next node
    print("None")  # Indicate the end of the linked list


def create_linked_list(values):
    if not values:  # If the list of values is empty
        return None  # Return None

    head = Node(values[0])  # Create the head node with the first value
    current = head  # Pointer to build the linked list
    for value in values[1:]:  # Iterate over the rest of the values
        current.next = Node(value)  # Create a new node and link it
        current = current.next  # Move to the new node
    return head  # Return the head of the linked list


# Driver code
if __name__ == "__main__":
    solution = Solution()  # Create an instance of the Solution class

    # Test Case 1: Unsorted linked list
    values = [4, 2, 1, 3]  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    sorted_head = solution.mergeSort(head)  # Sort the linked list
    print("Sorted list:")
    print_linked_list(sorted_head)  # Print the sorted list

    # Test Case 2: Empty linked list
    values = []  # No values
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    sorted_head = solution.mergeSort(head)  # Sort the linked list
    print("Sorted list:")
    print_linked_list(sorted_head)  # Print the sorted list

    # Test Case 3: Single element linked list
    values = [1]  # Single value
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    sorted_head = solution.mergeSort(head)  # Sort the linked list
    print("Sorted list:")
    print_linked_list(sorted_head)  # Print the sorted list

    # Test Case 4: Already sorted linked list
    values = [1, 2, 3, 4]  # Sorted values
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    sorted_head = solution.mergeSort(head)  # Sort the linked list
    print("Sorted list:")
    print_linked_list(sorted_head)  # Print the sorted list

    # Test Case 5: Linked list with duplicate values
    values = [4, 2, 2, 1, 3, 4]  # Values with duplicates
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    sorted_head = solution.mergeSort(head)  # Sort the linked list
    print("Sorted list:")
    print_linked_list(sorted_head)  # Print the sorted list
