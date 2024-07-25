class Node:
    def __init__(self, data):  # data -> value stored in node
        self.data = data
        self.next = None


class Solution:
    def addOne(self, head):
        # Reverse the linked list
        head = self.reverse(head)

        # Add one to the reversed list
        current = head
        carry = 1

        while current is not None:
            current.data += carry
            if current.data >= 10:
                current.data = 0
                carry = 1
            else:
                carry = 0
                break
            prev = current
            current = current.next

        # If carry is still left, add a new node at the end
        if carry == 1:
            prev.next = Node(1)

        # Reverse the list again to restore original order
        head = self.reverse(head)

        return head

    def reverse(self, head):
        prev = None
        current = head
        while current is not None:
            next_node = current.next
            current.next = prev
            prev = current
            current = next_node
        return prev


# Function to print the linked list
def print_linked_list(head):
    while head:
        print(head.data, end=" -> ")
        head = head.next
    print("None")


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
