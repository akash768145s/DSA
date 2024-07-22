class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    def union(self, head1, head2):
        # Step 1: Merge both linked lists into one list
        merged_list = self.merge_lists(head1, head2)

        # Step 2: Remove duplicates using a set
        unique_elements = set()
        current = merged_list
        while current:
            unique_elements.add(current.data)  # Add current node's data to set
            current = current.next  # Move to the next node

        # Step 3: Sort the unique elements
        sorted_elements = sorted(unique_elements)  # Sort the elements

        # Step 4: Construct the result linked list
        if not sorted_elements:
            return None

        result_head = Node(sorted_elements[0])  # Create head of result linked list
        current = result_head  # Initialize current node

        # Iterate over sorted elements to construct the result linked list
        for num in sorted_elements[1:]:
            new_node = Node(num)  # Create a new node
            current.next = new_node  # Link current node to the new node
            current = new_node  # Move current to the new node

        return result_head  # Return the head of the result linked list

    def merge_lists(self, head1, head2):
        # Function to merge two sorted linked lists
        dummy_head = Node(0)  # Dummy head to simplify the merging process
        current = dummy_head  # Pointer to build the merged list

        # Traverse both lists and merge them
        while head1 and head2:
            if head1.data < head2.data:
                current.next = head1  # Link current to head1
                head1 = head1.next  # Move head1 to its next node
            elif head1.data > head2.data:
                current.next = head2  # Link current to head2
                head2 = head2.next  # Move head2 to its next node
            else:
                current.next = head1  # Link current to head1
                head1 = head1.next  # Move head1 to its next node
                head2 = head2.next  # Move head2 to its next node
            current = current.next  # Move current to its next node

        # Append remaining nodes of head1 or head2
        if head1:
            current.next = head1
        elif head2:
            current.next = head2

        return dummy_head.next  # Return the merged list excluding the dummy head


# Driver code to test the union function
if __name__ == "__main__":
    # Example linked lists
    L1 = Node(9)
    L1.next = Node(6)
    L1.next.next = Node(4)
    L1.next.next.next = Node(2)
    L1.next.next.next.next = Node(3)
    L1.next.next.next.next.next = Node(8)

    L2 = Node(1)
    L2.next = Node(2)
    L2.next.next = Node(8)
    L2.next.next.next = Node(6)
    L2.next.next.next.next = Node(2)

    # Create an instance of Solution
    sol = Solution()

    # Call the union function and print the result
    result = sol.union(L1, L2)

    # Helper function to print the linked list
    def print_linked_list(head):
        while head:
            print(head.data, end=" ")
            head = head.next
        print()

    print("Output:")
    print_linked_list(result)  # Output: 1 2 3 4 6 8 9
