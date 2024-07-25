class Node:
    def __init__(self, x):
        # Initialize a node with data and next pointer
        self.data = x
        self.next = None

    @staticmethod
    def print_list(node):
        # Print the linked list
        while node is not None:
            # Print node data with '->' if there is a next node
            print(node.data, end=" -> " if node.next else "\n")
            node = node.next

class Solution:
    def sub_linked_list(self, h1, h2):
        # Remove leading zeros from the first list
        while h1 and h1.data == 0:
            h1 = h1.next

        # Remove leading zeros from the second list
        while h2 and h2.data == 0:
            h2 = h2.next

        # Get the lengths of both linked lists
        s1 = self.get_length(h1)
        s2 = self.get_length(h2)

        # If both lists are empty, return a new node with value 0
        if s1 == 0 and s2 == 0:
            return Node(0)

        # Ensure the first list is the larger one or equal in size
        if s2 > s1:
            h1, h2 = h2, h1  # Swap the lists

        # If both lists are of equal size, determine which list is larger
        if s1 == s2:
            curr1, curr2 = h1, h2
            while curr1 and curr2 and curr1.data == curr2.data:
                curr1 = curr1.next
                curr2 = curr2.next

            # If all nodes are equal, the result is 0
            if curr2 is None:
                return Node(0)

            # If the second list is larger, swap the lists
            if curr2.data > curr1.data:
                h1, h2 = h2, h1  # Swap the lists

        # Reverse both lists to facilitate subtraction
        h1 = self.reverse(h1)
        h2 = self.reverse(h2)

        ans = None  # Initialize the result list
        while h1:
            n1 = h1.data  # Get the data from the first list
            n2 = h2.data if h2 else 0  # Get the data from the second list, default to 0 if None
            
            # If n1 is less than n2, borrow from the next node
            if n1 < n2:
                if h1.next:
                    h1.next.data -= 1  # Borrow 1 from the next node
                n1 += 10  # Adjust n1 by adding 10

            # Create a new node with the difference and add it to the result list
            curr = Node(n1 - n2)
            curr.next = ans
            ans = curr

            h1 = h1.next  # Move to the next node in the first list
            if h2:
                h2 = h2.next  # Move to the next node in the second list

        # Remove leading zeros from the result list
        while ans and ans.next and ans.data == 0:
            ans = ans.next

        return ans  # Return the resulting list

    def get_length(self, head):
        # Compute the length of the linked list
        cnt = 0
        curr = head
        while curr:
            cnt += 1  # Increment count for each node
            curr = curr.next  # Move to the next node
        return cnt  # Return the length

    def reverse(self, head):
        # Reverse the linked list
        prev = None  # Initialize previous node as None
        curr = head  # Start with the head node
        while curr:
            next_node = curr.next  # Save the next node
            curr.next = prev  # Reverse the link
            prev = curr  # Move previous node to current
            curr = next_node  # Move to the next node
        return prev  # Return the new head of the reversed list

# Helper function to create a linked list from a list of values
def create_linked_list(values):
    if not values:
        return None
    head = Node(values[0])
    current = head
    for value in values[1:]:
        current.next = Node(value)
        current = current.next
    return head

# Test cases
def test_solution():
    solution = Solution()
    
    # Test Case 1: h1 = [7, 8, 6], h2 = [5, 3]
    h1 = create_linked_list([7, 8, 6])
    h2 = create_linked_list([5, 3])
    result = solution.sub_linked_list(h1, h2)
    print("Test Case 1 Result: ", end="")
    Node.print_list(result)  # Expected Output: 7 -> 3 -> 3

    # Test Case 2: h1 = [5, 6, 7], h2 = [2, 5]
    h1 = create_linked_list([5, 6, 7])
    h2 = create_linked_list([2, 5])
    result = solution.sub_linked_list(h1, h2)
    print("Test Case 2 Result: ", end="")
    Node.print_list(result)  # Expected Output: 5 -> 4 -> 2

    # Test Case 3: h1 = [1], h2 = [1]
    h1 = create_linked_list([1])
    h2 = create_linked_list([1])
    result = solution.sub_linked_list(h1, h2)
    print("Test Case 3 Result: ", end="")
    Node.print_list(result)  # Expected Output: 0

    # Test Case 4: h1 = [1, 0, 0, 0], h2 = [9, 9]
    h1 = create_linked_list([1, 0, 0, 0])
    h2 = create_linked_list([9, 9])
    result = solution.sub_linked_list(h1, h2)
    print("Test Case 4 Result: ", end="")
    Node.print_list(result)  # Expected Output: 1 -> 0 -> 0 -> 1

    # Test Case 5: h1 = [0, 0, 0], h2 = [0, 0, 0]
    h1 = create_linked_list([0, 0, 0])
    h2 = create_linked_list([0, 0, 0])
    result = solution.sub_linked_list(h1, h2)
    print("Test Case 5 Result: ", end="")
    Node.print_list(result)  # Expected Output: 0

# Run test cases
test_solution()
