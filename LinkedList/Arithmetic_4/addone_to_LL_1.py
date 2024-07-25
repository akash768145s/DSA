class Node:
    def __init__(self, data):  # data -> value stored in node
        self.data = data
        self.next = None

class Solution:
    def addOne(self, head):
        # Recursive helper function to add one to the linked list
        def addHelper(temp):
            if temp is None:  # Base case: if we've reached the end of the list
                return 1
            carry = addHelper(temp.next)  # Recursive call
            temp.data += carry  # Add carry to the current node's data
            if temp.data < 10:  # If no carry is generated, return 0
                return 0
            temp.data = 0  # If carry is generated, set current node's data to 0
            return 1  # Return carry

        carry = addHelper(head)  # Call the helper function
        if carry == 1:  # If there's a carry left after processing the whole list
            newNode = Node(1)  # Create a new node with value 1
            newNode.next = head  # Make the new node the new head
            head = newNode  # Update head to point to the new node
        return head  # Return the updated head

# Function to print the linked list
def print_linked_list(head):
    while head:
        print(head.data, end=' -> ')
        head = head.next
    print('None')

# Function to create a linked list from a list of values
def create_linked_list(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for value in values[1:]:
        current.next = Node(value)
        current = current.next
    return head

# Driver code
if __name__ == "__main__":
    values = [9, 9, 9]  # Example list to add one to
    head = create_linked_list(values)
    print("Original list:")
    print_linked_list(head)

    solution = Solution()
    new_head = solution.addOne(head)
    print("List after adding one:")
    print_linked_list(new_head)
