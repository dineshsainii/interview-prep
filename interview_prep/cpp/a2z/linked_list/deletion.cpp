#include <iostream>
#include <vector>

class Node
{
    public:
        int data;
        Node *next;
        Node(int idata) : data(idata), next(nullptr) {}

};

void Print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
}

Node* DeleteHead(Node *head)
{
    if (nullptr == head)
    {
        return head;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    Print(head);
    Node *newhead = DeleteHead(head);
    Print(head);


    return 0;
}