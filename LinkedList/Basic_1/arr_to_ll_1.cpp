#include <iostream>
#include <vector>
using namespace std;

// Node structure for a linked list
struct Node {
    int data;     // Data stored in the node
    Node* next;   // Pointer to the next node in the list

    // Constructor to initialize data and next pointer
    Node(int value) : data(value), next(nullptr) {}
};

// Function to construct a linked list from a vector of integers
Node* constructLL(vector<int>& arr) {
    Node* head = nullptr;  // Pointer to the head of the linked list
    Node* current = nullptr;  // Pointer to the current node being processed
    
    // Iterate through the vector
    for (int val : arr) {
        Node* new_node = new Node(val);  // Create a new node with the current value
        if (!head) {  // If head is nullptr, this is the first node
            head = new_node;  // Set head to point to the new node
            current = head;   // Also set current to point to the new node
        } else {  // If head is not nullptr, the list already has elements
            current->next = new_node;  // Link the current node to the new node
            current = new_node;  // Move the current pointer to the new node
        }
    }
    
    return head;  // Return the head of the constructed linked list
}

// Function to print the elements of a linked list
void printLL(Node* head) {
    Node* temp = head;  // Temporary pointer to traverse the linked list
    while (temp != nullptr) {
        cout << temp->data << " ";  // Print the data of the current node
        temp = temp->next;  // Move to the next node
    }
    cout << endl;
}

// Driver code to test the linked list construction
int main() {
    // Sample vector
    vector<int> arr = {1, 2, 3, 4, 5};
    
    // Construct the linked list from the vector
    Node* head = constructLL(arr);
    
    // Print the linked list
    cout << "Constructed Linked List: ";
    printLL(head);
    
    return 0;
}
