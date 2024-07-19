class Node:
    def __init__(self, val):
        self.next = None
        self.data = val


class Solution:
    # Function to remove a loop in the linked list.
    def removeLoop(self, head):
        # Check for edge cases: empty list or single node without loop
        if not head or not head.next:
            return head

        slow = head
        fast = head

        # Step 1: Detect the loop using Floyd’s cycle-finding algorithm
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            # If slow and fast pointers meet, a loop is detected
            if slow == fast:
                break
        else:
            # No loop detected
            return head

        # Step 2: Find the start node of the loop
        slow = head
        while slow != fast:
            slow = slow.next
            fast = fast.next

        # Step 3: Find the node just before the start node of the loop
        loop_start = slow
        current = loop_start
        while current.next != loop_start:
            current = current.next

        # Remove the loop
        current.next = None

        return head


# Helper function to print the linked list
def printList(head):
    temp = head
    while temp:
        print(temp.data, end=" ")
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

    # Print the linked list before removing the loop (loop will cause infinite print in actual scenario)
    # print("Linked list before removing loop:")
    # printList(head)  # Uncomment this line if you have a loop detection in place to avoid infinite printing

    # Remove loop from the linked list
    sol = Solution()
    head = sol.removeLoop(head)

    # Print the linked list after removing the loop
    print("Linked list after removing loop:")
    printList(head)
