#include <iostream>
#include <vector>

class Node
{
    public:
        int data;
        Node *prev;
        Node *next;
    Node(int idata) : data(idata), prev(nullptr), next(nullptr) {}
    Node(int idata, Node *iprev, Node *inext) : data(idata), prev(iprev), next(inext) {}
};

Node* ConvertArr2DLL(std::vector<int> &arr)
{
    if (arr.size() == 0)
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *previous = head;
    for (int i = 1; i<arr.size(); i++)
    {
        Node *temp = new Node(arr[i], previous, nullptr);
        previous->next = temp;
        previous = temp;
    }
    return head;
}

void Print(Node *head)
{
    if (head == nullptr)
    {
        std::cout << "Empty List\n";
        return;
    }
    Node *temp = head;
    Node *previous;
    //Forward pass
    while (temp)
    {
        previous = temp;
        std::cout << temp->data <<" ";
        temp = temp->next;
    }
    std::cout << std::endl;
    //Backward pass
    while (previous)
    {
        temp = previous;
        std::cout << previous-> data << " ";
        previous = previous->prev; 
    }
    std::cout << std::endl;
}

Node* DeleteHead(Node *head)
{
    //empty list
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *temp = head;
    head = head->next;
    if (head!=nullptr)
    {
        head->prev = nullptr;
    }

    delete temp;
    return head;
    
}

Node* DeleteTail(Node *head)
{
    if (head == nullptr)
        return nullptr;

    if (head->next == nullptr)
    {
        delete head;
        return nullptr;
    }

    Node *tail = head;
    //Traversing to tail
    while (tail->next)
    {
        tail = tail->next;
    }

    Node *prev = tail->prev;
    tail->prev = nullptr;
    prev->next = nullptr;
    delete tail;
    return head;
}

Node* deleteKth(Node *head, int k)
{
    //empty
    if (head == nullptr)
        return nullptr;

    Node *kth = head;
    int count = 0;
    //we are under the assumption that k is valid
    while (kth)
    {
        count++;
        if (count == k)
        {
            break;
        }
        kth = kth->next;
    }

    Node *front = kth->next;
    Node *previous = kth->prev;
    
    //EDGE CASES
    // only one node which is kth
    if (previous == nullptr && front == nullptr)
    {
        delete kth;
        return nullptr;
    }
    //at head
    else if (previous == nullptr)
    {
        return DeleteHead(head);
    }
    //at tail
    else if (front == nullptr)
    {
        return DeleteTail(head);
    }

    previous->next = front;
    front->prev = previous;
    kth->next = nullptr;
    kth->prev = nullptr;
    delete kth;

    return head;
}

int main()
{
    std::vector<int> arr = {12, 25, 37, 48};
    Node *head = ConvertArr2DLL(arr);
    Print(head);
    head = DeleteHead(head);
    Print(head);
    head = DeleteTail(head);
    Print(head);

    head = deleteKth(head, 1);
    Print(head);
    

    return 0;
}