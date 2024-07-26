class Node:
    def __init__(self, data=0, next=None, prev=None):
        self.data = data  # Initialize node data
        self.next = next  # Initialize the reference to the next node
        self.prev = prev  # Initialize the reference to the previous node


def deleteAllOccurrences(head: Node, k: int) -> Node:
    temp = head  # Start from the head of the doubly linked list
    while temp is not None:  # Traverse the list while there are nodes
        if (
            temp.data == k
        ):  # Check if the current node's data matches the target value k
            if temp == head:  # If the node to be deleted is the head node
                head = temp.next  # Move head to the next node
            nextNode = temp.next  # Get the next node
            prevNode = temp.prev  # Get the previous node
            if nextNode is not None:  # If the next node exists
                nextNode.prev = prevNode  # Update the next node's previous reference
            if prevNode is not None:  # If the previous node exists
                prevNode.next = nextNode  # Update the previous node's next reference

            temp = nextNode  # Move to the next node to continue deletion
        else:
            temp = (
                temp.next
            )  # Move to the next node if the current node is not to be deleted
    return head  # Return the potentially updated head of the list


# Helper function to create a doubly linked list from a list of values
def create_doubly_linked_list(values):
    if not values:  # If the input list is empty, return None
        return None
    head = Node(values[0])  # Create the head node with the first value
    curr = head  # Initialize curr to point to the head
    for value in values[1:]:  # Iterate over the remaining values
        new_node = Node(value)  # Create a new node
        curr.next = new_node  # Link the current node to the new node
        new_node.prev = curr  # Link the new node back to the current node
        curr = new_node  # Move to the newly created node
    return head  # Return the head of the doubly linked list


# Helper function to print the doubly linked list
def print_doubly_linked_list(head):
    curr = head  # Start from the head of the list
    while curr:  # Traverse the list while there are nodes
        print(
            curr.data, end=" <-> "
        )  # Print the current node's data followed by a delimiter
        curr = curr.next  # Move to the next node
    print("None")  # Print "None" at the end to signify the end of the list


# Driver code to test the deleteAllOccurrences function
def test_deleteAllOccurrences(values, k):
    print(f"Original list: {values}")
    head = create_doubly_linked_list(
        values
    )  # Create the doubly linked list from the values
    print("Before deletion:")
    print_doubly_linked_list(head)  # Print the list before deletion
    head = deleteAllOccurrences(head, k)  # Call the deleteAllOccurrences function
    print(f"After deleting all occurrences of {k}:")
    print_doubly_linked_list(head)  # Print the list after deletion


# Test cases
test_deleteAllOccurrences(
    [1, 2, 3, 4, 2, 5, 2], 2
)  # Expected output: 1 <-> 3 <-> 4 <-> 5 <-> None
test_deleteAllOccurrences(
    [1, 2, 3, 4, 5], 6
)  # Expected output: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> None (k not present)
test_deleteAllOccurrences(
    [7, 7, 7, 7], 7
)  # Expected output: None (all nodes have data k)
test_deleteAllOccurrences([], 3)  # Expected output: None (empty list)
test_deleteAllOccurrences(
    [5, 6, 7, 8, 9], 5
)  # Expected output: 6 <-> 7 <-> 8 <-> 9 <-> None (only one node with data k)
