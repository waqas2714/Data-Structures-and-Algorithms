#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
    node(int value = 0)
    {
        data = value;
        next = nullptr; // Initialize 'next' to nullptr here
    }
};


void insertAtHead(node* &head, int value){
    node* latest = new node(value);
    latest->next = head;
    head = latest;
}


void insertAtTail(node*& head, int value)
{
    node* temp = head;

    if (head == NULL)
    {
        node* latest = new node(value);
        head = latest;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    node* latest = new node(value);
    temp->next = latest;
}

void printList(node* head)
{
    node* temp = head;

    if (head == NULL)
    {
        cout << "NULL\n";
        return;
    }

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// void insertAtPosition(node* &head, int position, int value){
//     node* temp = head;
//     node* prevNode;
//     node* newNode = new node(value);
//     for (int i = 0; i < position - 1; i++)
//     {
//         if (temp->next != NULL && i != position)
//         {
//             prevNode = temp;
//             temp = temp->next;
//         }else{
//             cout << "Position is greater than the linked list\n";
//             return;
//         }        
//     }
//     prevNode->next = newNode;
//     newNode->next = temp;
// }

void insertAtPosition(node* &head, int position, int value){
    node* temp = head;
    node* prevNode = nullptr; // Initialize prevNode to nullptr
    node* newNode = new node(value);

    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    for (int i = 0; i < position; i++) {
        if (temp != NULL) {
            prevNode = temp;
            temp = temp->next;
        } else {
            cout << "Position is greater than the linked list\n";
            delete newNode; // Clean up the unused node
            return;
        }
    }

    prevNode->next = newNode;
    newNode->next = temp;
}


int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtHead(head, 4);
    insertAtPosition(head, 2, 69);
    printList(head);
    return 0;
}
