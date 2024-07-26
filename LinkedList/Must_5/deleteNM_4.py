class Node:
    def __init__(self, data):
        self.data = data  # Initialize the node with data
        self.next = None  # The next node reference is initially None


def linkdelete(head, n, m):
    count = 0  # Initialize the counter for nodes
    curr = head  # Start from the head of the linked list
    while curr and curr.next:  # Traverse the list while there are more nodes
        count += 1  # Increment the counter for every node
        x = n  # Copy the value of n to a temporary variable x
        if count == m:  # Check if the counter has reached m
            while (
                x > 0 and curr.next
            ):  # While x is greater than 0 and there are more nodes to delete
                curr.next = curr.next.next  # Skip the next node (delete it)
                x -= 1  # Decrement x
            count = 0  # Reset the counter after deletion
        curr = curr.next  # Move to the next node


def print_list(head):
    curr = head  # Start from the head of the list
    while curr:  # Traverse the list while there are more nodes
        print(
            curr.data, end=" -> "
        )  # Print the current node's data followed by an arrow
        curr = curr.next  # Move to the next node
    print("None")  # Print "None" at the end to signify the end of the list


# Helper function to create a linked list from a list of values
def create_linked_list(values):
    if not values:  # If the input list is empty, return None
        return None
    head = Node(values[0])  # Create the head node with the first value
    curr = head  # Initialize curr to point to the head
    for value in values[1:]:  # Iterate over the remaining values
        curr.next = Node(value)  # Create a new node and link it to the current node
        curr = curr.next  # Move to the newly created node
    return head  # Return the head of the linked list


# Driver code to test the linkdelete function
def test_linkdelete(values, n, m):
    print(f"Original list: {values}")  # Print the original list
    head = create_linked_list(values)  # Create a linked list from the values
    print("Before deletion:")
    print_list(head)  # Print the list before deletion
    linkdelete(head, n, m)  # Call the linkdelete function
    print(
        f"After deleting {n} nodes after every {m} nodes:"
    )  # Print the description of the operation
    print_list(head)  # Print the list after deletion


# Test cases
test_linkdelete(
    [1, 2, 3, 4, 5, 6, 7, 8, 9], 2, 3
)  # Test case with deletion of 2 nodes after every 3 nodes
test_linkdelete(
    [1, 2, 3, 4, 5, 6], 1, 2
)  # Test case with deletion of 1 node after every 2 nodes
test_linkdelete(
    [1, 2, 3, 4, 5], 3, 1
)  # Test case with deletion of 3 nodes after every 1 node
test_linkdelete(
    [1, 2, 3, 4, 5], 1, 5
)  # Test case with deletion of 1 node after every 5 nodes
test_linkdelete([1, 2, 3, 4, 5], 0, 2)  # Test case with no nodes deleted (n = 0)
