class Node:
    # Initialize the Node with value, next pointer, and child pointer
    def __init__(self, val=0, next=None, child=None):
        self.data = val
        self.next = next
        self.child = child

# Function to merge two linked lists
def merge(list1, list2):
    # Create a dummy node to help with merging
    dummyNode = Node(-1)
    # Pointer to the result linked list
    res = dummyNode
    # While both lists are not empty
    while list1 is not None and list2 is not None:
        # Compare the data in the current nodes of both lists
        if list1.data < list2.data:
            # Attach the node from list1 to the result list
            res.child = list1
            # Move the result pointer
            res = list1
            # Move to the next node in list1
            list1 = list1.child
        else:
            # Attach the node from list2 to the result list
            res.child = list2
            # Move the result pointer
            res = list2
            # Move to the next node in list2
            list2 = list2.child
        # Ensure the next pointer is null to break level links
        res.next = None
    # If list1 is not empty, attach the remaining nodes to the result list
    if list1:
        res.child = list1
    else:
        # If list2 is not empty, attach the remaining nodes to the result list
        res.child = list2

    # Ensure the first node's next pointer is nullified
    if dummyNode.child:
        dummyNode.child.next = None
    # Return the merged list, excluding the dummy node
    return dummyNode.child

# Function to flatten a multilevel linked list
def flattenLinkedList(head: Node) -> Node:
    # Base case: if the list is empty or has only one node
    if head is None or head.next is None:
        return head

    # Recursively flatten the rest of the list
    mergeHead = flattenLinkedList(head.next)

    # Merge the current head list with the flattened rest of the list
    head = merge(head, mergeHead)
    
    return head

# Driver code to test the implementation

# Helper function to print the flattened linked list
def printFlattenedList(head):
    # Pointer to traverse the list
    current = head
    # While there are nodes to print
    while current is not None:
        print(current.data, end=" -> ")
        current = current.child
    print("None")

# Test case 1
# Creating a sample multilevel linked list
# 1 - 2 - 3
# |   |
# 4   5 - 6
#         |
#         7

# Creating nodes
node1 = Node(1)
node2 = Node(2)
node3 = Node(3)
node4 = Node(4)
node5 = Node(5)
node6 = Node(6)
node7 = Node(7)

# Linking nodes to create the multilevel structure
node1.next = node2
node2.next = node3

node1.child = node4
node2.child = node5
node5.next = node6
node6.child = node7

# Flatten the linked list
flattened_head = flattenLinkedList(node1)

# Print the flattened list
print("Test Case 1:")
printFlattenedList(flattened_head)
# Expected output: 1 -> 4 -> 2 -> 5 -> 6 -> 7 -> 3 -> None

# Test case 2
# Creating another sample multilevel linked list
# 10 - 20 - 30
#  |    |
#  5    15 - 25
#             |
#             35

# Creating nodes
node10 = Node(10)
node20 = Node(20)
node30 = Node(30)
node5 = Node(5)
node15 = Node(15)
node25 = Node(25)
node35 = Node(35)

# Linking nodes to create the multilevel structure
node10.next = node20
node20.next = node30

node10.child = node5
node20.child = node15
node15.next = node25
node25.child = node35

# Flatten the linked list
flattened_head = flattenLinkedList(node10)

# Print the flattened list
print("Test Case 2:")
printFlattenedList(flattened_head)
# Expected output: 10 -> 5 -> 20 -> 15 -> 25 -> 35 -> 30 -> None

# Test case 3
# Creating a simple single level linked list
# 1 - 2 - 3 - 4

# Creating nodes
simple_node1 = Node(1)
simple_node2 = Node(2)
simple_node3 = Node(3)
simple_node4 = Node(4)

# Linking nodes to create the single level structure
simple_node1.next = simple_node2
simple_node2.next = simple_node3
simple_node3.next = simple_node4

# Flatten the linked list
flattened_head = flattenLinkedList(simple_node1)

# Print the flattened list
print("Test Case 3:")
printFlattenedList(flattened_head)
# Expected output: 1 -> 2 -> 3 -> 4 -> None

# Test case 4
# Edge case with an empty list

# Flatten the linked list
flattened_head = flattenLinkedList(None)

# Print the flattened list
print("Test Case 4:")
printFlattenedList(flattened_head)
# Expected output: None
