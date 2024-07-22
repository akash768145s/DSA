class Node:
    def __init__(self, data):
        self.data = data  # Value stored in the node
        self.next = None  # Pointer to the next node


class Solution:
    # Function to find the first node of the loop in the linked list.
    def findFirstNode(self, head):
        # Check if the list is empty or has only one node
        if not head or not head.next:
            return -1

        slow = head
        fast = head

        # Step 1: Detect the loop using Floyd’s cycle-finding algorithm
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            # If slow and fast pointers meet, a loop is detected
            if slow == fast:
                # Step 2: Find the starting node of the loop
                slow = head
                while slow != fast:
                    slow = slow.next
                    fast = fast.next
                return slow.data  # Return the data of the first node in the loop

        # No loop detected
        return -1


# Helper function to print the linked list
def printList(head):
    visited = set()
    temp = head
    while temp:
        if temp in visited:
            break
        print(temp.data, end=" ")
        visited.add(temp)
        temp = temp.next
    print()


# Helper function to create a linked list with a loop
def createListWithLoop():
    head = Node(1)
    second = Node(2)
    third = Node(3)
    fourth = Node(4)
    fifth = Node(5)

    head.next = second
    second.next = third
    third.next = fourth
    fourth.next = fifth
    fifth.next = second  # Creating a loop for testing

    return head


# Driver code
if __name__ == "__main__":
    # Create a linked list with a loop
    head = createListWithLoop()

    # Find the first node of the loop
    sol = Solution()
    loop_start_data = sol.findFirstNode(head)

    # Print the result
    if loop_start_data != -1:
        print(f"The first node of the loop has the data: {loop_start_data}")
    else:
        print("No loop detected in the linked list.")
