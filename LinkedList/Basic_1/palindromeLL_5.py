class ListNode:
    # Node class for a singly linked list
    def __init__(self, val=0, next=None):
        self.val = val  # Value of the node
        self.next = next  # Pointer to the next node

class Solution:
    # Solution class with methods to solve the problem
    def isPalindrome(self, head: ListNode) -> bool:
        # Method to check if the linked list is a palindrome
        if not head or not head.next:
            return True  # A list with 0 or 1 node is a palindrome

        # Step 1: Find the middle of the linked list
        slow, fast = head, head  # Initialize two pointers, slow and fast
        while fast and fast.next:
            slow = slow.next  # Move slow pointer by one step
            fast = fast.next.next  # Move fast pointer by two steps

        # Step 2: Reverse the second half of the linked list
        second_half = self.reverseList(slow)  # Reverse the second half starting from slow pointer

        # Step 3: Compare the first half with the reversed second half
        first_half = head  # Pointer to the start of the list
        while second_half:
            if first_half.val != second_half.val:
                return False  # If values do not match, it's not a palindrome
            first_half = first_half.next  # Move to the next node in the first half
            second_half = second_half.next  # Move to the next node in the second half

        return True  # All values matched, it's a palindrome

    def reverseList(self, head: ListNode) -> ListNode:
        # Helper method to reverse a linked list
        prev = None  # Initialize previous node to None
        current = head  # Start with the given head
        while current:
            next_node = current.next  # Store the next node
            current.next = prev  # Reverse the current node's pointer
            prev = current  # Move the previous pointer to the current node
            current = next_node  # Move to the next node in the list
        return prev  # New head of the reversed list

# Helper function to create a linked list from a list
def createLinkedList(arr):
    if not arr:
        return None  # If the list is empty, return None
    head = ListNode(arr[0])  # Create the head node
    current = head  # Start with the head node
    for val in arr[1:]:
        current.next = ListNode(val)  # Create the next node and link it
        current = current.next  # Move to the next node
    return head  # Return the head of the linked list

# Helper function to print a linked list
def printLinkedList(head):
    current = head  # Start with the head node
    while current:
        print(current.val, end=" -> ")  # Print the value of the current node
        current = current.next  # Move to the next node
    print("None")  # End of the linked list

# Example linked list: 1 -> 2 -> 2 -> 1
head = createLinkedList([1, 2, 2, 1])  # Create a linked list from the list
sol = Solution()  # Create an instance of the Solution class
print(sol.isPalindrome(head))  # Output: True, check if the list is a palindrome
