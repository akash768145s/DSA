class Node:
    def __init__(self, data):  # data -> value stored in node
        self.data = data
        self.next = None


def removeDuplicates(head):
    current = head  # Initialize current to the head of the list

    while (
        current is not None and current.next is not None
    ):  # Traverse until the end of the list
        if (
            current.data == current.next.data
        ):  # If current node has the same value as the next node
            current.next = current.next.next  # Skip the next node
        else:
            current = current.next  # Move to the next node if no duplicate was found

    return head  # Return the head of the modified list


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


# Function to print the linked list
def print_linked_list(head):
    current = head
    while current:
        print(current.data, end=" ")
        current = current.next
    print()


# Driver code
if __name__ == "__main__":
    values = [2, 2, 4, 5]  # Example input
    head = create_linked_list(values)  # Create linked list from values
    print("Original list:")
    print_linked_list(head)  # Print original list

    head = removeDuplicates(head)  # Remove duplicates
    print("List after removing duplicates:")
    print_linked_list(head)  # Print modified list
