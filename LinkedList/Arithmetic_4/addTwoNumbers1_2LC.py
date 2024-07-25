class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


from typing import Optional


class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy = ListNode()  # Create a dummy node to simplify list manipulation
        cur = dummy  # Initialize the current pointer to the dummy node
        carry = 0  # Initialize carry to 0

        # Iterate while there are nodes in either list or there is a carry
        while l1 or l2 or carry:
            # Get the value of the current node in l1, or 0 if l1 is None
            v1 = l1.val if l1 else 0
            # Get the value of the current node in l2, or 0 if l2 is None
            v2 = l2.val if l2 else 0

            # Calculate the sum of the values and the carry
            val = v1 + v2 + carry
            # Update carry for the next iteration
            carry = val // 10
            # Get the last digit of the sum for the current node
            val = val % 10
            # Create a new node with the computed value and attach it to the result list
            cur.next = ListNode(val)

            # Move the current pointer to the new node
            cur = cur.next
            # Move to the next node in l1, or set to None if at the end
            l1 = l1.next if l1 else None
            # Move to the next node in l2, or set to None if at the end
            l2 = l2.next if l2 else None

        # Return the next node of the dummy node which is the head of the result list
        return dummy.next


# Helper function to print the linked list
def printList(node: Optional[ListNode]) -> None:
    while node:
        print(node.val, end=" ")
        node = node.next
    print()


# Helper function to create a linked list from a list of integers
def createList(arr: list[int]) -> Optional[ListNode]:
    if not arr:
        return None
    head = ListNode(arr[0])
    current = head
    for num in arr[1:]:
        current.next = ListNode(num)
        current = current.next
    return head


# Example usage:

# Test case 1:
# l1 = 2 -> 4 -> 3 (represents 342)
# l2 = 5 -> 6 -> 4 (represents 465)
l1 = createList([2, 4, 3])  # Create the first linked list
l2 = createList([5, 6, 4])  # Create the second linked list

solution = Solution()  # Create an instance of the Solution class
result = solution.addTwoNumbers(l1, l2)  # Add the two linked lists

print("Output: ", end="")
printList(result)  # Print the resulting linked list
# Expected Output: 7 0 8 (represents 807, which is 342 + 465)

# Test case 2:
# l1 = 0 (represents 0)
# l2 = 0 (represents 0)
l1 = createList([0])  # Create the first linked list
l2 = createList([0])  # Create the second linked list

result = solution.addTwoNumbers(l1, l2)  # Add the two linked lists

print("Output: ", end="")
printList(result)  # Print the resulting linked list
# Expected Output: 0 (represents 0)

# Test case 3:
# l1 = 9 -> 9 -> 9 (represents 999)
# l2 = 1 (represents 1)
l1 = createList([9, 9, 9])  # Create the first linked list
l2 = createList([1])  # Create the second linked list

result = solution.addTwoNumbers(l1, l2)  # Add the two linked lists

print("Output: ", end="")
printList(result)  # Print the resulting linked list
# Expected Output: 0 0 0 1 (represents 1000, which is 999 + 1)
