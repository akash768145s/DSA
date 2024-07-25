class Node:
    def __init__(self, data):
        self.data = data      # Initialize the node with data
        self.next = None      # Initialize the next pointer to None

class Solution:
    # Function to reverse a linked list
    def reverse_list(self, list):
        prev = None            # Previous pointer, initially None
        curr = list            # Current pointer, initially pointing to the head of the list
        next = None            # Next pointer, initially None
        while curr is not None:   # Iterate until the end of the list
            next = curr.next     # Store the next node
            curr.next = prev     # Reverse the current node's pointer
            prev = curr          # Move the previous pointer to the current node
            curr = next          # Move the current pointer to the next node
        return prev             # Return the new head of the reversed list

    # Function to add two numbers represented by linked lists
    def addTwoLists(self, num1, num2):
        # Reverse both input linked lists to make addition easier
        first = self.reverse_list(num1)
        second = self.reverse_list(num2)

        carry = 0              # Initialize carry to 0
        sum_list = None        # Initialize the head of the resultant sum list to None

        # Loop until both lists are processed or there is a carry left
        while first is not None or second is not None or carry != 0:
            new_val = carry    # Start with the carry value
            if first is not None:     # If there are still nodes in the first list
                new_val += first.data    # Add the data of the current node of the first list
                first = first.next       # Move to the next node in the first list
            if second is not None:    # If there are still nodes in the second list
                new_val += second.data   # Add the data of the current node of the second list
                second = second.next     # Move to the next node in the second list
            carry = new_val // 10    # Update carry for the next position
            new_val = new_val % 10   # Get the current digit to store in the result list

            # Create a new node with the calculated value and add it to the front of the result list
            new_node = Node(new_val)
            new_node.next = sum_list
            sum_list = new_node

        return sum_list         # Return the head of the resultant sum list

# Helper function to print the linked list
def printList(node):
    while node is not None:    # Iterate until the end of the list
        print(node.data, end=' ')   # Print the data of the current node
        node = node.next          # Move to the next node
    print()                      # Print a newline at the end

# Helper function to create linked list from a list of integers
def createList(arr):
    if not arr:                 # If the input list is empty
        return None             # Return None
    head = Node(arr[0])         # Create the head node with the first element
    current = head              # Initialize current pointer to the head
    for num in arr[1:]:         # Iterate over the remaining elements
        current.next = Node(num)   # Create a new node and link it to the current node
        current = current.next    # Move the current pointer to the new node
    return head                # Return the head of the linked list

# Example usage:
# num1 = 4 -> 5 (represents the number 54)
# num2 = 3 -> 4 -> 5 (represents the number 543)
num1 = createList([4, 5])       # Create the first linked list
num2 = createList([3, 4, 5])    # Create the second linked list

solution = Solution()           # Create an instance of the Solution class
result = solution.addTwoLists(num1, num2)   # Add the two linked lists

print("Output: ", end='')       # Print the output label
printList(result)               # Print the resulting linked list
