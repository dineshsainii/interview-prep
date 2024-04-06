#include <iostream>

class Node
{
    public:
        int data;
        Node* next;

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
    std::cout << std::endl;
}



int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    Print(head);
    return 0;
}