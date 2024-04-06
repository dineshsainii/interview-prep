#include <iostream>


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
        std::cout <<  temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

Node* DeleteK(Node *head, int k)
{
    if (nullptr == head)
        return head;

    if (k==1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int count = 0;
    Node *prev = nullptr, *temp = head;
    while (temp!=nullptr)
    {   
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    Print(head);
    int k = 15;
    head = DeleteK(head, k);
    Print(head);
    return 0;
}