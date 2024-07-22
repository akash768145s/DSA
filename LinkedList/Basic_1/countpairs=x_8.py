class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    def countPair(self, head1, head2, n1, n2, x):
        # Create a set to store the elements of the first linked list
        elements_set = set()

        # Traverse the first linked list and add each element to the set
        current = head1
        while current:
            elements_set.add(current.data)
            current = current.next

        # Initialize a counter for the pairs
        pair_count = 0

        # Traverse the second linked list and check for pairs
        current = head2
        while current:     #***********************#
            if (x - current.data) in elements_set:
                pair_count += 1
            current = current.next

        return pair_count


# Helper function to create a linked list from a list of elements
def create_linked_list(arr):
    if not arr:
        return None
    head = Node(arr[0])
    current = head
    for item in arr[1:]:
        current.next = Node(item)
        current = current.next
    return head


# Example usage:
# Create linked lists from the given examples
head1 = create_linked_list([1, 2, 3, 4, 5, 6])
head2 = create_linked_list([11, 12, 13])
x = 15
n1 = 6
n2 = 3

# Create an instance of the Solution class and call the countPair method
solution = Solution()
result = solution.countPair(head1, head2, n1, n2, x)
print(result)  # Output: 3

# Another example
head1 = create_linked_list([7, 5, 1, 3])
head2 = create_linked_list([3, 5, 2, 8])
x = 10
n1 = 4
n2 = 4

result = solution.countPair(head1, head2, n1, n2, x)
print(result)  # Output: 2
