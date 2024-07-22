# Node class for the linked list
class Node:
    def __init__(self, data=None):
        self.data = data  # Data value of the node
        self.next = None  # Pointer to the next node

# Function to partition the list and return the pivot node
def partition(head, end):
    pivot = end  # Choose the last element as pivot
    prev = None  # Track the previous node
    curr = head  # Current node for traversal
    tail = pivot  # Tail to build the greater part

    while curr != pivot:
        next_node = curr.next  # Store the next node
        if curr.data < pivot.data:  # Nodes less than pivot go to the left part
            if prev is None:
                head = curr  # Update the head of the list
            prev = curr  # Move the previous node
        else:  # Nodes greater than pivot go to the right part
            if prev:
                prev.next = next_node  # Skip the current node
            tail.next = curr  # Append the current node to the end
            tail = curr  # Update the tail
            tail.next = None  # Disconnect the current node

        curr = next_node  # Move to the next node

    if prev is None:
        head = pivot  # If there were no nodes less than pivot, update head

    return head, pivot

# Function to perform QuickSort on the linked list
def quickSortRecur(head, end):
    if head is None or head == end:  # Base case for recursion
        return head

    head, pivot = partition(head, end)  # Partition the list and get the pivot node

    if head != pivot:
        temp = head
        while temp.next != pivot:
            temp = temp.next  # Move to the node just before the pivot
        temp.next = None  # Disconnect the left part from the pivot

        head = quickSortRecur(head, temp)  # Recursively sort the left part

        temp = get_tail(head)
        temp.next = pivot  # Reconnect the pivot

    pivot.next = quickSortRecur(pivot.next, end)  # Recursively sort the right part

    return head

# Function to get the last node of the linked list
def get_tail(node):
    while node is not None and node.next is not None:
        node = node.next
    return node

# Function to perform QuickSort on the linked list
def quickSort(head):
    end = get_tail(head)  # Get the last node
    return quickSortRecur(head, end)

# Function to print the linked list
def print_linked_list(head):
    while head:  # Traverse the linked list
        print(head.data, end=' -> ')  # Print the current node's data
        head = head.next  # Move to the next node
    print('None')  # Indicate the end of the linked list

# Function to create a linked list from a list of values
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
    # Test Case 1: Mixed values
    values = [3, 5, 8, 5, 10, 2, 1]  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = quickSort(head)  # Sort the linked list using QuickSort
    print("Sorted list:")
    print_linked_list(new_head)  # Print the sorted list

    # Test Case 2: All elements are the same
    values = [1, 1, 1, 1, 1]  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = quickSort(head)  # Sort the linked list using QuickSort
    print("Sorted list:")
    print_linked_list(new_head)  # Print the sorted list

    # Test Case 3: Already sorted list
    values = [1, 2, 3, 4, 5]  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = quickSort(head)  # Sort the linked list using QuickSort
    print("Sorted list:")
    print_linked_list(new_head)  # Print the sorted list

    # Test Case 4: Reverse sorted list
    values = [5, 4, 3, 2, 1]  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = quickSort(head)  # Sort the linked list using QuickSort
    print("Sorted list:")
    print_linked_list(new_head)  # Print the sorted list

    # Test Case 5: Single element
    values = [1]  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = quickSort(head)  # Sort the linked list using QuickSort
    print("Sorted list:")
    print_linked_list(new_head)  # Print the sorted list

    # Test Case 6: Empty list
    values = []  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = quickSort(head)  # Sort the linked list using QuickSort
    print("Sorted list:")
    print_linked_list(new_head)  # Print the sorted list
