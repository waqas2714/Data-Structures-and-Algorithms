#include <iostream>

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

// Function to check if a cycle exists in the linked list
int has_cycle(SinglyLinkedListNode* head) {
    

    SinglyLinkedListNode* hare = head;
    SinglyLinkedListNode* tortoise = head;

    while (hare != NULL && hare->next != nullptr) {
        tortoise = tortoise->next;     // Move tortoise one step
        hare = hare->next->next;       // Move hare two steps

        if (tortoise == hare) {
            return 1; // Cycle detected
        }
    }

    return 0; // No cycle found
}

// Function to insert a node at the end of the linked list
void insertNode(SinglyLinkedListNode* &head, int data) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode{data};
    if (head == nullptr) {
        head = newNode;
    } else {
        SinglyLinkedListNode* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int main() {
    SinglyLinkedListNode* head = nullptr;
    int n;
    std::cin >> n; // Number of elements in the linked list

    for (int i = 0; i < n; i++) {
        int data;
        std::cin >> data;
        insertNode(head, data);
    }

    // No need to create a cycle for testing here, as the linked list creation is based on input from stdin.

    int result = has_cycle(head);
    std::cout << result << std::endl; // Output should be 1 if a cycle is detected, 0 otherwise

    // Remember to free memory if not using a smart pointer or other memory management techniques
    // Clean up the linked list
    while (head != nullptr) {
        SinglyLinkedListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}