class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to remove duplicates from sorted linked list.
def removeDuplicates(head):
    # Create a dummy node with next pointing to head.
    dummy = Node(0)
    dummy.next = head
    prev = dummy  # Previous pointer initialized to dummy node.

    while head is not None:  # Traverse the linked list.
        # If current node has duplicate nodes ahead.
        if head.next is not None and head.data == head.next.data:
            # Skip all the nodes that have the same value.
            while head.next is not None and head.data == head.next.data:
                head = head.next
            prev.next = head.next  # Link previous node to the next unique node.
        else:
            prev = prev.next  # Move the previous pointer to the next node.
        head = head.next  # Move the head pointer to the next node.
    
    return dummy.next  # Return the new head of the modified list.

def print_linked_list(head):
    while head:  # Traverse the linked list.
        print(head.data, end=' -> ')  # Print the current node's data.
        head = head.next  # Move to the next node.
    print('None')  # Indicate the end of the linked list.

def create_linked_list(values):
    if not values:  # If the list of values is empty.
        return None  # Return None.
    
    head = Node(values[0])  # Create the head node with the first value.
    current = head  # Pointer to build the linked list.
    for value in values[1:]:  # Iterate over the rest of the values.
        current.next = Node(value)  # Create a new node and link it.
        current = current.next  # Move to the new node.
    return head  # Return the head of the linked list.

# Driver code
if __name__ == "__main__":
    # Test Case 1: Sorted linked list with duplicates
    values = [1, 1, 2, 3, 3, 4, 5, 5, 5, 6]  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = removeDuplicates(head)  # Remove duplicates from the linked list
    print("List after removing duplicates:")
    print_linked_list(new_head)  # Print the list after removing duplicates

    # Test Case 2: No duplicates
    values = [1, 2, 3, 4, 5, 6]  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = removeDuplicates(head)  # Remove duplicates from the linked list
    print("List after removing duplicates:")
    print_linked_list(new_head)  # Print the list after removing duplicates

    # Test Case 3: All duplicates
    values = [1, 1, 1, 1, 1]  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = removeDuplicates(head)  # Remove duplicates from the linked list
    print("List after removing duplicates:")
    print_linked_list(new_head)  # Print the list after removing duplicates

    # Test Case 4: Single element
    values = [1]  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = removeDuplicates(head)  # Remove duplicates from the linked list
    print("List after removing duplicates:")
    print_linked_list(new_head)  # Print the list after removing duplicates

    # Test Case 5: Empty list
    values = []  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = removeDuplicates(head)  # Remove duplicates from the linked list
    print("List after removing duplicates:")
    print_linked_list(new_head)  # Print the list after removing duplicates
