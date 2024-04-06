#include <iostream>
#include <vector>


class Node
{
    public:
        int data;
        Node *next;

        Node(int idata = 0, Node* inext = nullptr) : data(idata), next(inext) {}
};

Node* ConvertArr2LL(std::vector<int> arr)
{
    if (arr.size() == 0)
        return nullptr;
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for (int i = 1; i<arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

void Print(Node *head)
{
    if (head == nullptr)
    {
        std::cout << "Empty List" << std::endl;
        return;
    }
    Node *temp = head;
    while (temp)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

Node* DeleteTail(Node *head)
{
    if (head == nullptr)
    {
        std::cout << "Empty List" << std::endl;
        return nullptr;
    }
        
    
    Node *temp = head;
    if (temp->next == nullptr)
    {
        delete temp;
        return nullptr;
    }
    while (temp->next->next)
    {
        temp = temp->next;
    }

    Node *delNode = temp->next;
    temp->next = nullptr;
    delete delNode;
    return head;
}

int main()
{
    std::vector<int> arr = {10, 20, 30, 40, 50, 60, 70};
    Node *head = ConvertArr2LL(arr);
    Print(head);
    head = DeleteTail(head);
    std::cout << "After deleting tail: " << std::endl;
    Print(head);
    head = DeleteTail(head);
    Print(head);
    head = DeleteTail(head);
    Print(head);
    head = DeleteTail(head);
    Print(head);
    head = DeleteTail(head);
    Print(head);
    head = DeleteTail(head);
    Print(head);
    head = DeleteTail(head);
    Print(head);
    return 0;
}