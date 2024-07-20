class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def sortList(head):
    # If the list is empty or has only one element, it's already sorted
    if not head or not head.next:
        return head

    # Create dummy nodes for the three lists: zero, one, and two
    zeroHead = Node(-1)
    oneHead = Node(-1)
    twoHead = Node(-1)

    # Create pointers to track the end of the three lists
    zero = zeroHead
    one = oneHead
    two = twoHead

    # Traverse the original list and distribute the nodes into the three lists
    temp = head
    while temp:
        if temp.data == 0:
            zero.next = temp
            zero = zero.next
        elif temp.data == 1:
            one.next = temp
            one = one.next
        else:
            two.next = temp
            two = two.next
        temp = temp.next

    # Connect the three lists together
    # Connect the last node of the zero list to the first node of the one list
    zero.next = oneHead.next if oneHead.next else twoHead.next
    # Connect the last node of the one list to the first node of the two list
    one.next = twoHead.next
    # Terminate the last node of the two list
    two.next = None

    # The head of the sorted list is the first node of the zero list
    head = zeroHead.next

    return head


# Helper function to print the linked list
def printList(head):
    temp = head
    while temp:
        print(temp.data, end=" ")
        temp = temp.next
    print()


# Example usage
head = Node(1)
head.next = Node(2)
head.next.next = Node(0)
head.next.next.next = Node(1)
head.next.next.next.next = Node(2)
head.next.next.next.next.next = Node(0)

print("Original list:")
printList(head)

sorted_head = sortList(head)

print("Sorted list:")
printList(sorted_head)
