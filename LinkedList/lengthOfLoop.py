class Node:
    def __init__(self, data):
        self.data = data  # Value stored in the node
        self.next = None  # Pointer to the next node


def countNodesinLoop(head):
    # Function to find the length of a loop in the linked list.
    slow = head
    fast = head

    # Step 1: Detect the loop using Floyd’s cycle-finding algorithm
    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

        # If slow and fast pointers meet, a loop is detected
        if slow == fast:
            # Step 2: Find the length of the loop
            return lengthLoop(slow)

    # No loop detected
    return 0


def lengthLoop(node):
    # Function to find the length of the loop starting from the node
    count = 1
    current = node.next
    while current != node:
        count += 1
        current = current.next
    return count


# Helper function to create a linked list with a loop
def createListWithLoop():
    head = Node(1)
    second = Node(2)
    third = Node(3)
    fourth = Node(4)
    fifth = Node(5)

    head.next = second
    second.next = third
    third.next = fourth
    fourth.next = fifth
    fifth.next = third  # Creating a loop for testing

    return head


# Driver code
if __name__ == "__main__":
    # Create a linked list with a loop
    head = createListWithLoop()

    # Find the length of the loop
    loop_length = countNodesinLoop(head)

    # Print the result
    if loop_length > 0:
        print(f"The length of the loop is: {loop_length}")
    else:
        print("No loop detected in the linked list.")
