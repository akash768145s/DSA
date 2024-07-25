class Node:
    def __init__(self, val, next=None):
        # Initialize a node with value and next pointer
        self.data = val
        self.next = next


def findNthNode(temp: Node, k: int) -> Node:
    # Find the k-th node from the start of the list
    cnt = 1  # Initialize counter
    while temp is not None:
        if cnt == k:  # If counter matches k, return the current node
            return temp
        cnt += 1  # Increment counter
        temp = temp.next  # Move to the next node
    return temp  # Return None if k is out of bounds


def rotate(head: Node, k: int) -> Node:
    # Rotate the linked list by k positions
    if head is None or k == 0:  # If the list is empty or k is 0, no rotation is needed
        return head

    tail = head  # Start with the head
    length = 1  # Initialize length of the list
    while tail.next is not None:
        tail = tail.next  # Move to the end of the list
        length += 1  # Increment length

    if k % length == 0:  # If k is a multiple of length, no rotation is needed
        return head

    k = k % length  # Normalize k to prevent unnecessary rotations

    tail.next = head  # Connect the tail to the head to form a circular list

    # Find the new end of the list after rotation
    new_last_node = findNthNode(head, length - k)
    head = new_last_node.next  # Update head to the node after the new end
    new_last_node.next = None  # Break the circular link

    return head  # Return the new head of the rotated list


# Helper function to create a linked list from a list of values
def create_linked_list(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for value in values[1:]:
        current.next = Node(value)
        current = current.next
    return head


# Helper function to print the linked list
def print_linked_list(head):
    while head:
        print(head.data, end=" -> " if head.next else "\n")
        head = head.next


# Test cases
def test_rotate():
    # Test Case 1: Rotate by 2 positions
    head = create_linked_list([1, 2, 3, 4, 5])
    k = 2
    new_head = rotate(head, k)
    print("Test Case 1 Result: ", end="")
    print_linked_list(new_head)  # Expected Output: 4 -> 5 -> 1 -> 2 -> 3

    # Test Case 2: Rotate by 0 positions
    head = create_linked_list([1, 2, 3, 4, 5])
    k = 0
    new_head = rotate(head, k)
    print("Test Case 2 Result: ", end="")
    print_linked_list(new_head)  # Expected Output: 1 -> 2 -> 3 -> 4 -> 5

    # Test Case 3: Rotate by 5 positions (equal to the length of the list)
    head = create_linked_list([1, 2, 3, 4, 5])
    k = 5
    new_head = rotate(head, k)
    print("Test Case 3 Result: ", end="")
    print_linked_list(new_head)  # Expected Output: 1 -> 2 -> 3 -> 4 -> 5

    # Test Case 4: Rotate by 7 positions (more than the length of the list)
    head = create_linked_list([1, 2, 3, 4, 5])
    k = 7
    new_head = rotate(head, k)
    print("Test Case 4 Result: ", end="")
    print_linked_list(new_head)  # Expected Output: 4 -> 5 -> 1 -> 2 -> 3

    # Test Case 5: Rotate by 1 position
    head = create_linked_list([1, 2, 3, 4, 5])
    k = 1
    new_head = rotate(head, k)
    print("Test Case 5 Result: ", end="")
    print_linked_list(new_head)  # Expected Output: 5 -> 1 -> 2 -> 3 -> 4

    # Test Case 6: Rotate an empty list
    head = create_linked_list([])
    k = 3
    new_head = rotate(head, k)
    print("Test Case 6 Result: ", end="")
    print_linked_list(new_head)  # Expected Output: (no output, as the list is empty)


# Run test cases
test_rotate()
