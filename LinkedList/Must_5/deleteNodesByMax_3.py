class Node:
    # Initialize the Node with data and next pointer
    def __init__(self, x):
        self.data = x
        self.next = None


class Solution:
    # Function to reverse a linked list
    def reverse(self, root):
        prev = None  # Initialize previous node to None
        curr = root  # Start with the root node
        while curr is not None:  # Traverse the list
            next = curr.next  # Store the next node
            curr.next = prev  # Reverse the link
            prev = curr  # Move prev to the current node
            curr = next  # Move to the next node
        return prev  # prev is the new head of the reversed list

    # Function to compute the desired linked list
    def compute(self, head):
        head = self.reverse(head)  # Reverse the linked list
        curr = head  # Start with the new head
        maxi = head.data  # Initialize the maximum value
        prev = head  # Initialize the previous node
        head = head.next  # Move to the next node

        while head is not None:  # Traverse the reversed list
            if (
                head.data >= maxi
            ):  # If current node's data is greater than or equal to max
                maxi = head.data  # Update the maximum
                prev = head  # Move prev to the current node
                head = head.next  # Move to the next node
            else:
                prev.next = head.next  # Skip the current node
                head = prev.next  # Move head to the next node in the list

        head = self.reverse(curr)  # Reverse the list back to original order
        return head  # Return the head of the modified list


# Helper function to print the linked list
def printList(node):
    while node is not None:
        print(node.data, end=" -> ")
        node = node.next
    print("None")


# Driver code to test the implementation

# Creating the linked list
# 12 -> 15 -> 10 -> 11 -> 5 -> 6 -> 2 -> 3
head = Node(12)
head.next = Node(15)
head.next.next = Node(10)
head.next.next.next = Node(11)
head.next.next.next.next = Node(5)
head.next.next.next.next.next = Node(6)
head.next.next.next.next.next.next = Node(2)
head.next.next.next.next.next.next.next = Node(3)

# Creating the solution object
sol = Solution()

# Printing the original list
print("Original Linked List:")
printList(head)

# Computing the result
result = sol.compute(head)

# Printing the modified list
print("Modified Linked List:")
printList(result)
