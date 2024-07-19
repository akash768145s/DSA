class ListNode:
    def __init__(self, data=0, next=None):
        self.data = data
        self.next = next

class Solution:
    def searchKey(self, n, head, key):
        # Initialize the current node to the head of the linked list
        current = head
        
        # Traverse the linked list until the end
        while current is not None:
            # Check if the current node's data matches the key
            if current.data == key:
                # If found, return True
                return True
            # Move to the next node
            current = current.next
        
        # If the key is not found in the entire list, return False
        return False

# Test Cases

# Helper function to create a linked list from a list of values
def create_linked_list(values):
    if not values:
        return None
    head = ListNode(values[0])
    current = head
    for value in values[1:]:
        current.next = ListNode(value)
        current = current.next
    return head

# Test Case 1
# Linked list: 1 -> 2 -> 3 -> 4 -> 5
head1 = create_linked_list([1, 2, 3, 4, 5])
sol = Solution()
print(sol.searchKey(5, head1, 3))  # Output: True

# Test Case 2
# Linked list: 1 -> 2 -> 3 -> 4 -> 5
head2 = create_linked_list([1, 2, 3, 4, 5])
print(sol.searchKey(5, head2, 6))  # Output: False

# Test Case 3
# Linked list: empty
head3 = create_linked_list([])
print(sol.searchKey(0, head3, 1))  # Output: False

# Test Case 4
# Linked list: 10 -> 20 -> 30 -> 40 -> 50
head4 = create_linked_list([10, 20, 30, 40, 50])
print(sol.searchKey(5, head4, 50))  # Output: True

# Test Case 5
# Linked list: 7 -> 14 -> 21 -> 28
head5 = create_linked_list([7, 14, 21, 28])
print(sol.searchKey(4, head5, 14))  # Output: True
