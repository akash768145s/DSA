class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def findIntersection(firstHead, secondHead):
    if firstHead is None or secondHead is None:
        return None
    
    temp1 = firstHead
    temp2 = secondHead
    
    while temp1 != temp2:
        temp1 = temp1.next if temp1 else secondHead
        temp2 = temp2.next if temp2 else firstHead
    
        if temp1 == temp2:
            return temp1
    
        if temp1 is None:
            temp1 = secondHead
        if temp2 is None:
            temp2 = firstHead
    
    return temp1

# Helper function to create a linked list from a list of values
def create_linked_list(arr):
    if not arr:
        return None
    head = Node(arr[0])
    current = head
    for val in arr[1:]:
        current.next = Node(val)
        current = current.next
    return head

# Driver code to test the function
if __name__ == "__main__":
    # Example 1: Intersection case
    # 3 -> 1 -> 2 -> 15 -> 30
    firstHead = create_linked_list([3, 1, 2])
    intersect = Node(15)
    intersect.next = Node(30)
    firstHead.next.next.next = intersect

    # 10 -> 9 -> 15 -> 30
    secondHead = create_linked_list([10, 9])
    secondHead.next.next = intersect

    result = findIntersection(firstHead, secondHead)
    if result:
        print("Intersection at node with data:", result.data)  # Output: Intersection at node with data: 15
    else:
        print("No intersection")

    # Example 2: No intersection case
    # 3 -> 4 -> 5 -> 6
    firstHead = create_linked_list([3, 4, 5, 6])

    # 2 -> 1 -> 4
    secondHead = create_linked_list([2, 1, 4])

    result = findIntersection(firstHead, secondHead)
    if result:
        print("Intersection at node with data:", result.data)  # Output: No intersection
    else:
        print("No intersection")
