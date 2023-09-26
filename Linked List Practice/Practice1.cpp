#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;

    node(int value) : data(value), next(nullptr){};
};

void addToList(node* &head, int value)
{
    node *temp = head;
    node *newNode = new node(value);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    for (int i = 0; temp->next != nullptr; i++)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void displayFromStart(node* head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

void reverse(node* &head){
    node* prev = nullptr; 
    node* next = nullptr; 
    node* current = head;

    while (current != nullptr)
    {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;  
    }

    head = prev;

}


int main()
{   
    node* head = nullptr; 
    addToList(head, 10);
    addToList(head, 15);
    addToList(head, 20);
    displayFromStart(head);
    reverse(head);
    displayFromStart(head);
    return 0;
}
