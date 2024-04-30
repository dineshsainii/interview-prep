#include <iostream>
#include <vector>

class Node
{
    public:
        int data;
        Node *next;

        Node(int idata = 0, Node* inext = nullptr) : data(idata), next(inext) {}
};

Node* ConvertArr2LL(std::vector<int> &arr)
{
    if (arr.size() == 0)
        return nullptr;
    Node* head = new Node(arr[0]);
    Node *temp = head;
    for (size_t i = 1; i<arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
}

void Print(Node* head)
{
    if (head == nullptr)
    {
        std::cout << "Empty list" << std::endl;
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

Node* DeleteHead(Node* head)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    Node *temp = head;
    if (head->next == nullptr)
    {
        delete temp;
        return nullptr;
    }
    else
    {
        head = temp->next;
        temp->next = nullptr;
        delete temp;
    }
    return head;
}

Node* DeleteLast(Node* head)
{
    if (head == nullptr)
    {
        std::cout << "Empty linkedlist" << std::endl;
        return nullptr;
    }

    Node* temp = head;
    if (head->next == nullptr)
    {
        temp->next = nullptr;
        delete temp;
        return nullptr;
    }
    while (temp->next->next)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* DeleteK(Node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    Node *temp = head;
    if (k==1)
    {
        head = head->next;
        delete temp;
        return head;
    }
    int count = 0;
    Node *prev = head;
    while (temp)
    {
        count++;
        if (k==count)
        {
            prev->next = temp->next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    std::cout << "K given invalid. greater than LL size" << std::endl;
    return head;
}

int main()
{   
    std::vector<int> arr = {10,20,30,40,50,60};
    Node* head = ConvertArr2LL(arr);
    Print(head);
    //Delete head of LL
    // head = DeleteHead(head);
    // Print(head);
    //Delete last node of LL
    // head = DeleteLast(head);
    // Print(head);
    // head = DeleteLast(head);
    // Print(head);

    head = DeleteK(head, 7);
    Print(head);
    return 0;
}