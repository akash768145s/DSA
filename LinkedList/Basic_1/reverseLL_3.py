class node:
    def __init__(self, val):
        self.data = val  # Initialize the data of the node
        self.next = None  # Initialize the next pointer to None


class Solution:
    # Function to reverse a linked list iteratively (O(1) space complexity).
    def reverseList(self, head):
        prev = None  # Initialize prev to None
        current = head  # Start with the head of the list
        while current is not None:  # Traverse until the end of the list
            next_node = current.next  # Save the next node
            current.next = prev  # Reverse the pointer
            prev = current  # Move prev to the current node
            current = next_node  # Move current to the next node
        return prev  # Return the new head of the reversed list

# Initial:
# 1 -> 2 -> 3 -> 4 -> 5 -> None
# prev = None
# current = 1

# After Iteration 1:
    
# 1 -> None
# 2 -> 3 -> 4 -> 5 -> None
# prev = 1
# current = 2

# After Iteration 2:


# 2 -> 1 -> None
# 3 -> 4 -> 5 -> None
# prev = 2
# current = 3

# After Iteration 3:


# 3 -> 2 -> 1 -> None
# 4 -> 5 -> None
# prev = 3
# current = 4
# After Iteration 4:

# 4 -> 3 -> 2 -> 1 -> None
# 5 -> None
# prev = 4
# current = 5
# After Iteration 5:

# 5 -> 4 -> 3 -> 2 -> 1 -> None
# prev = 5
# current = None



# Helper function to print the linked list
def print_list(head):
    current = head
    while current is not None:
        print(current.data, end=" -> ")
        current = current.next
    print("None")


# Helper function to create a linked list from a list of values
def create_list(values):
    if not values:
        return None
    head = node(values[0])
    current = head
    for value in values[1:]:
        current.next = node(value)
        current = current.next
    return head


# Driver code to test the reverseList function
if __name__ == "__main__":
    # Create a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> None
    values = [1, 2, 3, 4, 5]
    head = create_list(values)

    # Print the original linked list
    print("Original list:")
    print_list(head)

    # Reverse the linked list
    sol = Solution()
    reversed_head = sol.reverseList(head)

    # Print the reversed linked list
    print("Reversed list:")
    print_list(reversed_head)
