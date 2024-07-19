#include <iostream> // Include the input-output stream library
using namespace std; // Use the standard namespace

// Node structure definition
struct Node {
    int data; // Data part of the node
    Node* next; // Pointer to the next node
    // Constructor to initialize a new node
    Node(int val) : data(val), next(nullptr) {}
};

// Function to create a linked list from an array
Node* arrayToLinkedList(int arr[], int size) {
    // If the array is empty, return null
    if (size == 0) return nullptr;

    // Create the head node with the first element of the array
    Node* head = new Node(arr[0]);
    Node* current = head; // Initialize current node to head

    // Iterate through the array and create nodes
    for (int i = 1; i < size; i++) {
        current->next = new Node(arr[i]); // Link the new node to the current node
        current = current->next; // Move the current pointer to the new node
    }

    return head; // Return the head of the linked list
}

// Function to delete the k-th node from the linked list
void deleteKthNode(Node*& head, int k) {
    // If linked list is empty or k is out of bounds, return
    if (head == nullptr || k <= 0) return;

    Node* temp = head; // Initialize temp to head

    // If head needs to be removed (k == 1)
    if (k == 1) {
        head = temp->next; // Change head to the next node
        delete temp; // Free old head
        return;
    }

    // Find the k-1 node
    for (int i = 1; temp != nullptr && i < k-1; i++) {
        temp = temp->next; // Move to the next node
    }

    // If the k-th node doesn't exist, return
    if (temp == nullptr || temp->next == nullptr) return;

    // Node temp->next is the k-th node to be deleted
    Node* nodeToDelete = temp->next; // Save pointer to the k-th node

    // Unlink the k-th node from linked list
    temp->next = nodeToDelete->next; // Link k-1 node to k+1 node

    // Free memory of the k-th node
    delete nodeToDelete;
}

// Helper function to print the linked list
void printList(Node* head) {
    // Iterate through the list and print each node's data
    while (head != nullptr) {
        cout << head->data << " "; // Print data of current node
        head = head->next; // Move to the next node
    }
    cout << endl; // Print newline at the end
}

int main() {
    // Initialize an array
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate size of the array

    // Convert array to linked list
    Node* head = arrayToLinkedList(arr, size);

    // Print the original linked list
    cout << "Original List: ";
    printList(head);

    int k = 3; // Position of the node to delete
    // Delete the k-th node
    deleteKthNode(head, k);

    // Print the linked list after deletion
    cout << "List after deleting " << k << "-th node: ";
    printList(head);

    return 0; // Return success
}
