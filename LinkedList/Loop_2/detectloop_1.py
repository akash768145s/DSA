# Node class to represent each node in the linked list
class Node:
    def __init__(self, data):  # data -> value stored in node
        self.data = data
        self.next = None


# Solution class with a function to detect a loop in a linked list
class Solution:
    # Function to check if the linked list has a loop.
    def detectLoop(self, head):
        # Initializing two pointers, slow and fast
        slow = head
        fast = head

        # Loop until fast pointer reaches the end of the list
        while fast is not None and fast.next is not None:
            # Move slow pointer one step ahead
            slow = slow.next
            # Move fast pointer two steps ahead
            fast = fast.next.next

            # If slow and fast pointers meet, there is a loop
            if slow == fast:
                return True

        # If fast pointer reaches the end, there is no loop
        return False


# Function to create a loop in the linked list for testing purposes
def createLoop(head, position):
    if position == -1:
        return

    # Initialize loop point and end pointer
    loop_point = head
    end = head

    # Move loop_point to the desired position
    for _ in range(position):
        loop_point = loop_point.next

    # Move end pointer to the end of the list
    while end.next is not None:
        end = end.next

    # Create loop by pointing end's next to loop_point
    end.next = loop_point


# Function to print the linked list (useful for debugging, not used here)
def printList(head):
    current = head
    while current is not None:
        print(current.data, end=" -> ")
        current = current.next
    print("None")


# Driver code
if __name__ == "__main__":
    # Creating nodes
    head = Node(1)
    second = Node(2)
    third = Node(3)
    fourth = Node(4)
    fifth = Node(5)

    # Connecting nodes to form a linked list: 1 -> 2 -> 3 -> 4 -> 5
    head.next = second
    second.next = third
    third.next = fourth
    fourth.next = fifth

    # Creating a loop in the linked list. Let's create a loop at position 2 (0-based index)
    createLoop(head, 2)

    # Creating an object of Solution class
    solution = Solution()

    # Checking if there is a loop in the linked list
    if solution.detectLoop(head):
        print("Loop detected")
    else:
        print("No loop detected")
