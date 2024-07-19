#include <iostream>

// Node class definition
class Node
{
public:
    int data;
    Node *next;

    // Constructors
    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node *next) : data(data), next(next) {}
};

// Function to calculate the length of a linked list
int length(Node *head)
{
    // Initialize length counter
    int count = 0;

    // Traverse the linked list
    Node *current = head;
    while (current != nullptr)
    {
        // Increment count for each node encountered
        count++;
        // Move to the next node
        current = current->next;
    }

    return count; // Return the length of the linked list
}

// Driver code for explanation
int main()
{
    // Creating a sample linked list
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Calling the length function to calculate the length of the linked list
    int len = length(head);

    // Displaying the length of the linked list
    std::cout << "Length of the linked list: " << len << std::endl;

    // Cleaning up memory (deallocating memory for dynamically allocated nodes)
    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
