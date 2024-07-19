class Node:
    def __init__(self, val):
        self.data = val  # Initialize the data part of the node
        self.next = None  # Initialize the next pointer to None

class LinkedList:
    def __init__(self):
        self.head = None  # Initialize the head of the list to None

    # Function to insert a node at the head
    def insert_at_head(self, val):
        new_node = Node(val)  # Create a new node
        new_node.next = self.head  # Point the new node to the current head
        self.head = new_node  # Update the head to the new node

    # Function to insert a node at the end
    def insert_at_end(self, val):
        new_node = Node(val)  # Create a new node
        if self.head is None:  # If the list is empty
            self.head = new_node  # Make the new node the head
            return

        temp = self.head  # Temporary pointer to traverse the list
        while temp.next is not None:  # Traverse to the end of the list
            temp = temp.next
        temp.next = new_node  # Point the last node to the new node

    # Function to insert a node at the kth position
    def insert_at_kth(self, val, k):
        if k <= 0:
            return  # If the position is invalid, do nothing
        new_node = Node(val)  # Create a new node
        if k == 1:  # If inserting at the head
            new_node.next = self.head
            self.head = new_node
            return
        temp = self.head  # Temporary pointer to traverse the list
        for _ in range(1, k - 1):
            if temp is None:
                return  # If k is greater than the length of the list, do nothing
            temp = temp.next
        if temp is None:
            return  # If k is greater than the length of the list, do nothing
        new_node.next = temp.next  # Point the new node to the kth node
        temp.next = new_node  # Point the (k-1)th node to the new node

    # Function to insert a node before a specific value
    def insert_before_value(self, val, target):
        if self.head is None:
            return  # If the list is empty, do nothing
        if self.head.data == target:  # If the target is at the head
            self.insert_at_head(val)  # Insert at the head
            return
        new_node = Node(val)  # Create a new node
        temp = self.head  # Temporary pointer to traverse the list
        while temp.next is not None and temp.next.data != target:
            temp = temp.next
        if temp.next is None:
            return  # If target is not found, do nothing
        new_node.next = temp.next  # Point the new node to the target node
        temp.next = new_node  # Point the previous node to the new node

    # Function to insert a node after a specific value
    def insert_after_value(self, val, target):
        temp = self.head  # Temporary pointer to traverse the list
        while temp is not None and temp.data != target:
            temp = temp.next
        if temp is None:
            return  # If target is not found, do nothing
        new_node = Node(val)  # Create a new node
        new_node.next = temp.next  # Point the new node to the next node
        temp.next = new_node  # Point the target node to the new node

    # Function to print the linked list
    def print_list(self):
        temp = self.head  # Temporary pointer to traverse the list
        while temp is not None:  # Traverse the entire list
            print(temp.data, end=" ")  # Print the data
            temp = temp.next  # Move to the next node
        print()  # Newline for better readability

# Example usage:
if __name__ == "__main__":
    linked_list = LinkedList()  # Create a linked list

    # Test case 1: Insert at the head
    linked_list.insert_at_head(10)
    linked_list.print_list()  # Output: 10

    # Test case 2: Insert at the end
    linked_list.insert_at_end(20)
    linked_list.print_list()  # Output: 10 20

    # Test case 3: Insert at kth position
    linked_list.insert_at_kth(15, 2)
    linked_list.print_list()  # Output: 10 15 20

    # Test case 4: Insert before a specific value
    linked_list.insert_before_value(5, 10)
    linked_list.print_list()  # Output: 5 10 15 20

    # Test case 5: Insert after a specific value
    linked_list.insert_after_value(25, 20)
    linked_list.print_list()  # Output: 5 10 15 20 25
