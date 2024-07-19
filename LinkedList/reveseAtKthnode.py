# Node class to represent each element in the linked list
class Node:
    # Constructor to initialize node's data and next pointer
    def __init__(self, data, next_node=None):
        self.data = data
        self.next = next_node


# Function to reverse a linked list using the three-pointer approach
def reverseLinkedList(head):
    temp = head  # Initialize 'temp' at the head of the linked list
    prev = None  # Initialize 'prev' to None, representing the previous node

    # Iterate through the linked list until 'temp' is None
    while temp is not None:
        front = temp.next  # Store the next node in 'front' to preserve the reference
        temp.next = prev  # Reverse the direction of the current node's 'next' pointer to point to 'prev'
        prev = temp  # Move 'prev' to the current node, for the next iteration
        temp = front  # Move 'temp' to 'front' node, advancing traversal

    return prev  # Return the new head of the reversed linked list


# Function to get the Kth node from a given position in the linked list
def getKthNode(temp, k):
    k -= 1  # Decrement K as we already start from the 1st node

    # Decrement K until it reaches the desired position
    while temp is not None and k > 0:
        k -= 1  # Decrement k as temp progresses
        temp = temp.next  # Move to the next node

    return temp  # Return the Kth node


# Function to reverse nodes in groups of K
def kReverse(head, k):
    temp = head  # Initialize a temporary node to traverse the list
    prevLast = None  # Initialize a pointer to track the last node of the previous group

    # Traverse through the linked list
    while temp is not None:
        kThNode = getKthNode(temp, k)  # Get the Kth node of the current group

        # If the Kth node is NULL (not a complete group)
        if kThNode is None:
            if prevLast:  # If there was a previous group,
                prevLast.next = temp  # link the last node to the current node
            break  # Exit the loop

        nextNode = kThNode.next  # Store the next node after the Kth node
        kThNode.next = None  # Disconnect the Kth node to prepare for reversal
        reverseLinkedList(temp)  # Reverse the nodes from temp to the Kth node

        # Adjust the head if the reversal starts from the head
        if temp == head:
            head = kThNode
        else:
            prevLast.next = kThNode  # Link the last node of the previous group to the reversed group

        prevLast = temp  # Update the pointer to the last node of the previous group
        temp = nextNode  # Move to the next group

    return head  # Return the head of the modified linked list


# Function to print the linked list
def printLinkedList(head):
    temp = head  # Initialize temp to head
    while temp is not None:  # Traverse until the end of the linked list
        print(temp.data, end=" ")  # Print the data of the current node
        temp = temp.next  # Move to the next node
    print()  # Print a newline after the linked list


# Node class to represent each element in the linked list
class Node:
    # Constructor to initialize node's data
    def __init__(self, data):
        self.data = data
        self.next = None


# Create a linked list with values 5, 4, 3, 7, 9, and 2
head = Node(5)
head.next = Node(4)
head.next.next = Node(3)
head.next.next.next = Node(7)
head.next.next.next.next = Node(9)
head.next.next.next.next.next = Node(2)

# Print the original linked list
print("Original Linked List: ", end="")
printLinkedList(head)

# Reverse the linked list in groups of K
head = kReverse(head, 4)

# Print the reversed linked list
print("Reversed Linked List: ", end="")
printLinkedList(head)
