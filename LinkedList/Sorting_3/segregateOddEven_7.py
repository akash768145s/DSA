# Node class for the linked list
class Node:
    def __init__(self, data=None):
        self.data = data  # Data value of the node
        self.next = None  # Pointer to the next node

class Solution:
    def divide(self, N, head):
        even = None  # Head of the even sublist
        odd = None  # Head of the odd sublist
        e = None  # Pointer to the current end of the even sublist
        o = None  # Pointer to the current end of the odd sublist

        while head:  # Traverse the linked list
            if head.data % 2 == 0:  # Check if the current node is even
                if even is None:  # If the even sublist is empty
                    even = head  # Set the head of the even sublist
                    e = head  # Set the pointer to the current end of the even sublist
                else:  # If the even sublist is not empty
                    e.next = head  # Link the current even node to the end of the even sublist
                    e = e.next  # Move the pointer to the new end of the even sublist
            else:  # If the current node is odd
                if odd is None:  # If the odd sublist is empty
                    odd = head  # Set the head of the odd sublist
                    o = head  # Set the pointer to the current end of the odd sublist
                else:  # If the odd sublist is not empty
                    o.next = head  # Link the current odd node to the end of the odd sublist
                    o = o.next  # Move the pointer to the new end of the odd sublist
            head = head.next  # Move to the next node in the list

        if e:  # If there are any even nodes
            e.next = odd  # Link the even sublist to the odd sublist
        if o:  # If there are any odd nodes
            o.next = None  # Ensure the last node of the odd sublist points to None

        if even:  # If there are any even nodes
            return even  # Return the head of the even sublist (now the head of the modified list)
        else:
            return odd  # If there are no even nodes, return the head of the odd sublist

# Function to print the linked list
def print_linked_list(head):
    while head:  # Traverse the linked list
        print(head.data, end=' -> ')  # Print the current node's data
        head = head.next  # Move to the next node
    print('None')  # Indicate the end of the linked list

# Function to create a linked list from a list of values
def create_linked_list(values):
    if not values:  # If the list of values is empty
        return None  # Return None
    
    head = Node(values[0])  # Create the head node with the first value
    current = head  # Pointer to build the linked list
    for value in values[1:]:  # Iterate over the rest of the values
        current.next = Node(value)  # Create a new node and link it
        current = current.next  # Move to the new node
    return head  # Return the head of the linked list

# Driver code
if __name__ == "__main__":
    solution = Solution()

    # Test Case 1: Mixed even and odd numbers
    values = [1, 2, 3, 4, 5, 6]  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = solution.divide(len(values), head)  # Divide the linked list
    print("List after dividing:")
    print_linked_list(new_head)  # Print the list after dividing

    # Test Case 2: All even numbers
    values = [2, 4, 6, 8, 10]  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = solution.divide(len(values), head)  # Divide the linked list
    print("List after dividing:")
    print_linked_list(new_head)  # Print the list after dividing

    # Test Case 3: All odd numbers
    values = [1, 3, 5, 7, 9]  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = solution.divide(len(values), head)  # Divide the linked list
    print("List after dividing:")
    print_linked_list(new_head)  # Print the list after dividing

    # Test Case 4: Single element
    values = [1]  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = solution.divide(len(values), head)  # Divide the linked list
    print("List after dividing:")
    print_linked_list(new_head)  # Print the list after dividing

    # Test Case 5: Empty list
    values = []  # Values for the linked list
    head = create_linked_list(values)  # Create the linked list
    print("Original list:")
    print_linked_list(head)  # Print the original list

    new_head = solution.divide(len(values), head)  # Divide the linked list
    print("List after dividing:")
    print_linked_list(new_head)  # Print the list after dividing
