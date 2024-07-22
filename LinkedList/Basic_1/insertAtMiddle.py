# Node class definition
class Node:
    def __init__(self, data):  # data -> value stored in node
        self.data = data
        self.next = None


# Solution class with the insertInMiddle method
class Solution:
    def insertInMiddle(self, head, x):
        if not head:
            return Node(x)  # If the list is empty, return a new node as the head

        # Step 1: Use slow and fast pointers to find the middle of the linked list
        slow, fast = head, head  # Initialize slow and fast pointers
        while fast and fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next

        # Step 2: Create the new node with the given value x
        new_node = Node(x)

        # Step 3: Insert the new node after the slow pointer
        new_node.next = slow.next
        slow.next = new_node

        return head


# Helper function to create a linked list from a list
def createLinkedList(arr):
    if not arr:
        return None  # If the list is empty, return None
    head = Node(arr[0])  # Create the head node
    current = head  # Start with the head node
    for val in arr[1:]:
        current.next = Node(val)  # Create the next node and link it
        current = current.next  # Move to the next node
    return head  # Return the head of the linked list


# Helper function to print a linked list
def printLinkedList(head):
    current = head  # Start with the head node
    while current:
        print(current.data, end=" -> ")  # Print the value of the current node
        current = current.next  # Move to the next node
    print("None")  # End of the linked list


# Example usage
head = createLinkedList([10, 20, 40, 50])
sol = Solution()
head = sol.insertInMiddle(head, 60)  # Insert 30 in the middle of the linked list
printLinkedList(head)  # Output: 10 -> 20 -> 30 -> 40 -> 50 -> None
