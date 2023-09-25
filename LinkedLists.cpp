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

int main()
{
    node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtHead(head, 4);
    printList(head);
    return 0;
}
